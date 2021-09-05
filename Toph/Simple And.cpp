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
int sub[100005];
int
void dfs(int u,int par){
    sub[u]=1;
    for(int v:g[u]){
        if(v==par) continue;
        level[v]=level[u]+1;
        dfs(v,u);
        sub[u]+=sub[v];
    }
    st.push(u);
}
int a[100005];
vector<int> tree[500000];
void build(int n,int b,int e){
    if(b==e){
        tree[n].pb(a[node[b]]);
        return;
    }
    int mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    merge(tree[n*2].begin(),tree[n*2].end(),tree[n*2+1].begin(),tree[n*2+1].end(),back_inserter(tree[n]));
}
int main()
{
    int t;
    cin>>t;
    int n,q,s,x,y;
    cin>>n>>q>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(s,-1);

    int idx=1;
    while(!s.empty()){
        int u=s.top(); s.pop();
        node[u]=idx;
        node1[idx]=u;
        idx++;
    }

    return 0;
}


