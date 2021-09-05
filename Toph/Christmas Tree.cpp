/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

ll a[100005],d[100005],ans[100005],MOD[22],v[100005][22];
vector<ll> g[100005];
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
ll phi(ll n){
    ll ans=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i) continue;
        ans=(ans*(i-1))/i;
        while(n%i==0){
            n/=i;
        }
    }
    if(n!=1){
        ans=(ans*(n-1))/n;
    }
    return ans;
}
ll dfs(ll u,ll x){
    //cout<<u<<"  "<<x<<endl;
    if(g[u].size()==0) return a[u];
    if(v[u][x]!=-1) return v[u][x];
    ll r=0;
    for(ll v:g[u]){
        ll y=dfs(v,x+1);
        //cout<<u<<" "<<v<<" "<<x<<" "<<y<<endl;
        r=(r+bigmod(a[u],y,MOD[x]))%MOD[x];
    }
    //cout<<u<<" "<<x<<" "<<r<<endl;
    return v[u][x]=r;
}
int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    MOD[1]=1000000007;
    for(int i=2;i<=20;i++){
        MOD[i]=phi(MOD[i-1]);
        //cout<<MOD[i]<<endl;
    }

    scanf("%lld %lld %lld",&n,&m,&k);

    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&x);
        for(int j=1;j<=x;j++){
            scanf("%lld",&y);
            d[y]=i;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld",&x,&y);
        if(d[x]<d[y]) g[x].pb(y);
        else g[y].pb(x);
    }

    memset(v,-1,sizeof(v));
    for(int i=1;i<=n;i++){
        ans[i]=dfs(i,1);
    }

    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&x);
        printf("%lld\n",ans[x]);
    }

    return 0;
}


