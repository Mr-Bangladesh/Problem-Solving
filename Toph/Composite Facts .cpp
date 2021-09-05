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

ll fact[1000005];

ll F(ll n){
    ll x=(n*(n+1))/2; x--;
    x=x%MOD;
    ll ans=(x+(fact[n]*(n-1))%MOD)%MOD;
    return ans%MOD;
}

ll tree[8000000],a[1000005];

void build(ll node,ll b,ll e)
{
    if(b==e){
        tree[node]=F(a[b]);
        return;
    }
    ll left=node*2; ll right=node*2+1; ll mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=(tree[left]+tree[right])%MOD;
}
ll Query(ll node,ll b,ll e,ll i,ll j)
{
    if(e<i || b>j) return 0;
    else if(b>=i && e<=j) return tree[node];
    ll mid=(b+e)/2; ll left=node*2; ll right=left+1;
    ll P1=Query(left,b,mid,i,j);
    ll P2=Query(right,mid+1,e,i,j);
     return (P1+P2)%MOD;
}
void update(ll node,ll b,ll e,ll i,ll value)
{
    if(i<b || i>e) return;
    else if(i==b && b==e)
    {
        tree[node]=F(value);
        return;
    }
    ll left=node*2; ll right=left+1; ll mid=(b+e)/2;
    if(i<=mid) update(left,b,mid,i,value);
    else update(right,mid+1,e,i,value);
    tree[node]=(tree[right] + tree[left])%MOD;
}


int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    fact[0]=1;
    for(int i=1;i<=1000000;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }

    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(ll i=1;i<=q;i++){
        ll l;
        cin>>x>>l>>r;
        if(x==1){
            update(1,1,n,l,r);
        }
        else{
            ll ans=Query(1,1,n,l,r);
            cout<<ans<<endl;
        }
    }


    return 0;
}
