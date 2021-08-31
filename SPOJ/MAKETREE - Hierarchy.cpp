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
#define EPS 1e-9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

vector<int> g[100005];
stack<int> st;
bitset<100005> mark;
void dfs(int u){
    mark[u]=1;
    for(int v:g[u]){
        if(mark[v]==0){
            dfs(v);
        }
    }
    st.push(u);
}
int main()
{
    int n,k,x,y;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>x;
        for(int j=1;j<=x;j++){
            cin>>y;
            g[i].pb(y);
        }
    }
    for(int i=1;i<=n;i++){
        if(mark[i]==0){
            dfs(i);
        }
    }
    int ans[100005];
    int par=0;
    while(!st.empty()){
        int u=st.top(); st.pop();
        ans[u]=par;
        par=u;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;

    return 0;
}


