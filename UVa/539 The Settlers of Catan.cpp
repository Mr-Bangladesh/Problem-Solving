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
vector<int> g[30];
int mark[30][30],ans;
void f(int u,int dist){
    ans=max(ans,dist);
    for(int v:g[u]){
        if(!mark[u][v] && !mark[v][u]){
            mark[u][v]=mark[v][u]=1;
            ans=max(ans,dist); //cout<<"marked "<<u<<" "<<v<<"  "<<v<<" "<<u<<endl;
            //cout<<dist<<" visited edge "<<u<<" "<<v<<endl;
            f(v,dist+1);
            mark[u][v]=mark[v][u]=0;
            //cout<<"deleted "<<u<<" "<<v<<"  "<<v<<" "<<u<<endl;
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m),n||m){
        int x,y;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&x,&y); //x++; y++;
            g[x].pb(y);
            g[y].pb(x);
        }
        ans=0;
        for(int i=0;i<n;i++){
            memset(mark,0,sizeof(mark));
            f(i,0);
        }
        printf("%d\n",ans);

        for(int i=0;i<n;i++) g[i].clear();
    }

    return 0;
}

