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
int n,cap[205],g[205][205],x,y,w,a,b,barisal[205],dhaka[205],m;
int minflow,par[205];
void augmented_path(int u,int minval){
    if(u==0){
        minflow=minval;
        return;
    }
    else if(par[u]!=-1){
        augmented_path(par[u],min(minval,g[par[u]][u]));
        g[par[u]][u]-=minflow;
        g[u][par[u]]+=minflow;
    }
}
int main()
{
    while(scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&cap[i]);
            g[i][n+i]=cap[i];
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&x,&y,&w);
            g[x+n][y]=w;
        }
        scanf("%d %d",&a,&b);
        for(int i=1;i<=a;i++){
            scanf("%d",&barisal[i]);
            g[0][barisal[i]]=INT_MAX;
        }
        for(int i=1;i<=b;i++){
            scanf("%d",&dhaka[i]);
            g[dhaka[i]+n][n*2+1]=INT_MAX;
        }
        int total_flow=0;
        while(1){
            minflow=0;
            int mark[n*2+5]={0};
            mark[0]=1;
            par[0]=-1;
            queue<int> q;
            q.push(0);
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int i=1;i<=n*2+1;i++){
                    if(g[u][i]>0 && mark[i]==0){
                        mark[i]=1;
                        q.push(i);
                        par[i]=u;
                    }
                }
            }
            augmented_path(n*2+1,INT_MAX);
            if(!minflow) break;
            total_flow+=minflow;
        }
        printf("%d\n",total_flow);

        memset(par,0,sizeof(par));
        memset(g,0,sizeof(g));
        memset(cap,0,sizeof(cap));
        memset(dhaka,0,sizeof(dhaka));
        memset(barisal,0,sizeof(barisal));
    }

    return 0;
}

