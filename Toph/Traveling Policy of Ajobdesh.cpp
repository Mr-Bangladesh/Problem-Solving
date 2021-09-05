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

map<ll, vector<ll> > g,G;
map<ll,ll> mark,d,D;
void bfs(ll s){
    queue<ll> q; q.push(s);
    mark[s]=1;
    d[s]=0;
    while(!q.empty()){
        ll u=q.front(); q.pop();
        for(ll v:g[u]){
            if(!mark[v]){ //cout<<u<<" "<<v<<endl;
                mark[v]=1;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
void bfs2(ll s){
    queue<ll> q; q.push(s);
    mark[s]=1;
    D[s]=0;
    while(!q.empty()){
        ll u=q.front(); q.pop();
        for(ll v:G[u]){
            if(!mark[v]){ //cout<<u<<" "<<v<<endl;
                mark[v]=1;
                D[v]=D[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    for(cs=1;cs<=t;cs++){
        printf("Case %lld:\n",cs);
        cin>>n>>m>>k>>q;
        for(int i=1;i<=m;i++){
            cin>>x>>y;
            g[x].pb(y);
            G[y].pb(x);
        }
        for(int i=0;i<n;i++) d[i]=-1;

        for(int i=0;i<n;i++) D[i]=-1;

        bfs(k);
        mark.clear();
        bfs2(k);
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            if(D[x]==-1 || d[y]==-1){
                printf("Not possible to go from %lld to %lld.\n",x,y);
            }
            else{
                printf("The shortest distance from %lld to %lld is %lld.\n",x,y,D[x]+d[y]);
            }
        }
        g.clear();
        mark.clear();
        d.clear();
        G.clear();
        D.clear();
    }

    return 0;
}



