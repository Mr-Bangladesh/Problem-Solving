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
vector<int> g[200005];
ll a[200005],mx[200005],sum[200005];
void dfs(int u,int par){
    sum[u]=a[u];
    for(int v:g[u]){
        if(v==par) continue;
        dfs(v,u);
        sum[u]+=sum[v];
    }
}
void dfs1(int u,int par){
    mx[u]=sum[u];
    for(int v:g[u]){
        if(v==par) continue;
        dfs1(v,u);
        mx[u]=max(mx[u],mx[v]);
    }
}
int main()
{
    int n,q,x,y;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,-1);
    dfs1(1,-1);
    while(q--){
        cin>>x;
        cout<<mx[x]<<endl;
    }

    return 0;
}


