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

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,x,y;
        scanf("%d %d",&n,&m);
        vector<int> g[3002];
        set<int> node;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            if(x<y) g[x].pb(y);
            else g[y].pb(x);
            node.insert(x); node.insert(y);
        }
        for(auto x:node){
            sort(g[x].begin(),g[x].end());
        }
        set<set<int> > ans;
        for(auto x:node){
            for(int u:g[x]){
                for(int v:g[u]){
                    if(binary_search(g[x].begin(),g[x].end(),v)){
                        ans.insert({x,u,v});
                    }
                }
            }
        }
//        for(auto it:ans){
//            for(auto it1:it) cout<<it1<<" "; cout<<endl;
//        }
//        cout<<ans.size()<<endl;
        printf("%d\n",ans.size());
    }

    return 0;
}

