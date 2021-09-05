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
string s;
ll tree[500005][30];
void build(ll n,ll b,ll e){
    if(b==e){
        tree[n][s[b-1]-96]=1;
        return;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    for(int i=1;i<=26;i++){
        tree[n][i]=tree[n*2][i]+tree[n*2+1][i];
        //cout<<n<<" "<<i<<" "<<tree[n][i]<<endl;
    }
}
void update(ll n,ll b,ll e,ll i,ll v){
    if(b>i || e<i) return;
    if(b==e && b==i){
        for(int k=1;k<=26;k++) tree[n][k]=0;
        tree[n][v]=1;
        return;
    }
    ll mid=(b+e)/2;
    update(n*2,b,mid,i,v);
    update(n*2+1,mid+1,e,i,v);
    for(int i=1;i<=26;i++){
        tree[n][i]=tree[n*2][i]+tree[n*2+1][i];
    }
}
ll query(ll n,ll b,ll e,ll i,ll j,ll v){
    //cout<<n<<" "<<b<<" "<<e<<" "<<i<<" "<<j<<" "<<v<<endl;
    if(b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[n][v];
    }
    ll mid=(b+e)/2;
    ll x=query(n*2,b,mid,i,j,v);
    ll y=query(n*2+1,mid+1,e,i,j,v);
    return x+y;
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n>>m;
    cin>>s;
    build(1,1,n);
    while(m--){
        cin>>r;
        if(r==1){
            char c;
            cin>>x>>c;
            update(1,1,n,x,c-96);
        }
        else{
            char c;
            cin>>x>>y>>c;
            ll ans=query(1,1,n,x,y,c-96);
            cout<<ans<<endl;
        }
    }

    return 0;
}

