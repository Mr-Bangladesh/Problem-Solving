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

int n,s,t,m,x,y,w,g[101][101],par[101];
int minedge;
void augmented_path(int u,int minval){
    //cout<<u<<" "<<minval<<endl;
    if(u==s){
        minedge=minval;
        return;
    }
    else if(par[u]!=-1){
        augmented_path(par[u],min(minval,g[par[u]][u]));
        g[par[u]][u]-=minedge;
        g[u][par[u]]+=minedge;
    }
}

int main()
{
    int cs=1;
    while(scanf("%d",&n)){
        if(!n) break;
        scanf("%d %d %d",&s,&t,&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&x,&y,&w);
            g[x][y]+=w;
            g[y][x]+=w;
        }
        int total_flow=0;
        while(1){
            minedge=0;
            int mark[n+1]={0};
            mark[s]=1;
            queue<int> q;
            q.push(s);
            par[s]=-1; //cout<<"started "<<s<<endl;
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
            augmented_path(t,1e7);
            //cout<<s<<" "<<t<<"  flow "<<minedge<<endl;
            if(!minedge) break;
            total_flow+=minedge;
        }
        printf("Network %d\n",cs++);
        printf("The bandwidth is %d.\n\n", total_flow);
        memset(g,0,sizeof(g));
        memset(par,0,sizeof(par));
    }

    return 0;
}

