/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

struct edge{
    int At,Cost;
    edge(int a,int b){
        At=a; Cost=b;
    }
};
bool operator<(edge a,edge b){
    return a.Cost>b.Cost;
}
int n,m,x,y,w,mark[102][102],par[102];
vector< pair<int,int> > g[102];
void augmented_path(int u){
    if(u==1){
        return;
    }
    else{
        augmented_path(par[u]);
        mark[u][par[u]]=0;
        mark[par[u]][u]=0;
    }
}
int main()
{
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&x,&y,&w);
            g[x].pb(mp(y,w));
            g[y].pb(mp(x,w));
            mark[x][y]=1;
            mark[y][x]=1;
        }
        bool res=true;
        int ans=0;
        for(int check=1;check<=2;check++){
            int dist[n+2];
            for(int i=1;i<=n;i++) dist[i]=1e7;

            priority_queue< edge> pq;
            pq.push(edge(1,0));
            dist[1]=0;
            par[1]=-1;
            while(!pq.empty()){
                auto u=pq.top(); pq.pop();
                if(u.Cost!=dist[u.At]) continue;
                for(auto v:g[u.At]){
                    if(mark[u.At][v.first]==0) continue;
                    if(dist[u.At]+v.second<dist[v.first]){
                        dist[v.first]=dist[u.At]+v.second;
                        pq.push(edge(v.first,dist[v.first]));
                        par[v.first]=u.At;
                    }
                }
            }
            if(dist[n]==1e7){
                res=false; break;
            }
            augmented_path(n);
            ans+=dist[n];
        }
        if(res){
            printf("%d\n",ans);
        }
        else{
            printf("Back to jail\n");
        }
        memset(mark,0,sizeof(mark));
        memset(par,0,sizeof(par));
        for(int i=1;i<=n;i++) g[i].clear();
    }

    return 0;
}

