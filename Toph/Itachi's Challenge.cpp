/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
ll a[100005];
//tree[500005],prop[500005];
struct value{
    ll sum;
    ll prop;
};
value tree[500005];
void build(ll n,ll b,ll e){
    if(b==e){
        tree[n].sum=a[b];
        return;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    tree[n].sum=(tree[n*2].sum+tree[n*2+1].sum)%MOD;
}
void update(ll n,ll b,ll e,ll i,ll j,ll v){
    if(i>e || j<b) return;
    if(b>=i && e<=j){
        ll x=((e-b+1)*v)%MOD;
        tree[n].sum=(tree[n].sum+x)%MOD;
        tree[n].prop=(tree[n].prop+v)%MOD;
        return;
    }
    ll mid=(b+e)/2;
    update(n*2,b,mid,i,j,v);
    update(n*2+1,mid+1,e,i,j,v);
    tree[n].sum=(tree[n*2].sum+tree[n*2+1].sum+(e-b+1)*tree[n].prop)%MOD;
}
ll query(ll n,ll b,ll e,ll i,ll j,ll carry){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j){
        return (tree[n].sum+(e-b+1)*carry)%MOD;
    }
    ll mid=(b+e)/2;
    ll x=query(n*2,b,mid,i,j,carry+tree[n].prop);
    ll y=query(n*2+1,mid+1,e,i,j,carry+tree[n].prop);
    return (x+y)%MOD;
}
ll bigmod(ll B,ll P,ll M){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=bigmod(B,P/2,M);
        return ((R%M)*(R%M))%M;
    }
    else{
        ll R=bigmod(B,P-1,M);
        return ((R%M)*(B%M))%M;
    }
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>q;
    build(1,1,n);
    while(q--){
        cin>>x>>y>>k;
        ll d=query(1,1,n,x,y,0);
        ll c=y-x+2;
        ll p=(bigmod(c,k,MOD)-1)%MOD;
        ll q=bigmod(c-1,MOD-2,MOD);
        ll sum=((p%MOD)*(q%MOD))%MOD;
        sum=(sum*d)%MOD;
        //cout<<x<<" "<<y<<" "<<k<<" "<<d<<" "<<sum<<endl;
        update(1,1,n,x,y,sum);
    }
    for(int i=1;i<=n;i++){
        ll x=query(1,1,n,i,i,0);
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}

