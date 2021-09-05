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

int n,s,t,m,x,y,w,g[101][101],par[101],g1[100][100],edge[101][101];
int minedge;
void augmented_path(int u,int minval){
    //cout<<u<<" "<<minval<<endl;
    if(u==1){
        minedge=minval;
        return;
    }
    else if(par[u]!=-1){
        augmented_path(par[u],min(minval,g[par[u]][u]));
        g[par[u]][u]-=minedge;
        g[u][par[u]]+=minedge;

        g1[par[u]][u]-=minedge;
        g1[u][par[u]]-=minedge;
    }
}
vector<int> v1,v2;
void bfs(int ss,int idx){
    int mark[n+3]={0};
    mark[ss]=1;
    queue<int> q;
    q.push(ss);
    while(!q.empty()){
        int u=q.front(); q.pop();
        if(idx==1) v1.pb(u);
        else v2.pb(u);
        for(int v=1;v<=n;v++){
            if(g1[u][v]>0 && mark[v]==0){
                mark[v]=1;
                q.push(v); //cout<<ss<<" "<<u<<" visited "<<v<<endl;
            }
        }
    }
}
int main()
{
    int cs=1;
    while(scanf("%d %d",&n,&m)){
        if(n==0 && m==0) break;
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&x,&y,&w);
            g[x][y]=w;
            g[y][x]=w;
            g1[x][y]=w;
            g1[y][x]=w;
            edge[x][y]=w;
            edge[y][x]=w;
        }
        int total_flow=0;
        while(1){
            minedge=0;
            int mark[n+1]={0};
            mark[1]=1;
            queue<int> q;
            q.push(1);
            par[1]=-1; //cout<<"started "<<1<<endl;
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int i=1;i<=n;i++){
                    if(g[u][i]>0 && mark[i]==0){
                        mark[i]=1;
                        q.push(i);
                        par[i]=u; //cout<<"visited "<<u<<" "<<i<<endl;
                    }
                }
            }
            augmented_path(2,1e7);
            //cout<<1<<" "<<2<<"  flow "<<minedge<<endl;
            if(!minedge) break;
            total_flow+=minedge;
        }
        bfs(1,1);
        bfs(2,2);
        vector< pair<int,int> > ans;
        for(int u:v1){
            for(int v:v2){
                if(edge[u][v]>0) ans.pb(mp(u,v));
            }
        }
        for(auto it:ans){
            printf("%d %d\n",it.first,it.second);
        }
        printf("\n");
        memset(g1,0,sizeof(g1));
        memset(edge,0,sizeof(edge));
        memset(g,0,sizeof(g));
        memset(par,0,sizeof(par));
        v1.clear(); v2.clear();
    }

    return 0;
}

