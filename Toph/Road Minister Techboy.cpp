#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
map<ll,vector< pair<ll,ll> > > g;
map<ll,ll> dist;
ll mx=-1;

void dfs(ll u,ll par){
    mx=max(mx,dist[u]);
    for(auto v:g[u]){
        if(v.first==par) continue;
        dist[v.first]=dist[u]+v.second;
        dfs(v.first,u);
    }
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    for(cs=1;cs<=t;cs++){
        cin>>n;
        ll sum=0;
        for(int i=1;i<n;i++){
            cin>>x>>y>>w;
            sum+=w;
            g[x].pb(mp(y,w));
            g[y].pb(mp(x,w));
        }
        dist[1]=0;
        dfs(1,-1);

        ll d=(sum-mx)*2 + mx;

        printf("Case %lld: %lld\n",cs,d);

        g.clear(); dist.clear();
        mx=0;
    }

    return 0;
}



