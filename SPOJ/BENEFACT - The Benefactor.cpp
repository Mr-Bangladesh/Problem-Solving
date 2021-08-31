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

map<ll, vector < pair<ll,ll> > > g;
map<ll,ll> level;
map<ll,bool> mark;
void dfs(ll u){
    mark[u]=true;
    for(auto v:g[u]){
        if(!mark[v.first]){
            level[v.first]=level[u]+v.second;
            dfs(v.first);
        }
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<n;i++){
            cin>>x>>y>>w;
            g[x].pb(mp(y,w));
            g[y].pb(mp(x,w));
        }
        dfs(1);
        ll s=0,mx=-1;
        for(int i=1;i<=n;i++){
            if(level[i]>mx){
                mx=level[i];
                s=i;
            }
        }
        level.clear();
        mark.clear();
        dfs(s);
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,level[i]);
        }
        cout<<ans<<endl;

        level.clear();
        mark.clear();
        g.clear();
    }

    return 0;
}



