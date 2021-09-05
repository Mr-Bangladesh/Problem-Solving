// Problem: Do You Know Tree ?
// Contest: Toph
// URL: https://toph.co/p/do-you-know-tree
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 1000005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
vector< pair<int,ll> > g[maxn];
int par[maxn];
ll dist[maxn]; int mark[maxn];
ll curmax; int curnode;
void dfs(int u){
	if(dist[u]>curmax){
		curmax=dist[u];
		curnode=u;
	}
	for(auto it:g[u]){
		int v=it.first; ll w=it.second;
		if(v==par[u]) continue;
		par[v]=u;
		dist[v]=dist[u]+w;
		dfs(v);
	}
}
int root[maxn];
ll a[maxn];
void dfs2(int u,int p,int r){
	root[u]=r;
	a[u]=0;
	for(auto it:g[u]){
		int v=it.first; ll w=it.second;
		if(v==p || mark[v]) continue;
		dfs2(v,u,r);
		a[u]=max(a[u],a[v]+w);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int x,y;
	ll w;
	for(int i=1;i<n;i++){
		scanf("%d %d %lld",&x,&y,&w);
		g[x].pb(mp(y,w));
		g[y].pb(mp(x,w));
	}
	int source=1;
	for(int i=1;i<=n;i++){
		if(g[i].size()==1){
			source=i;
			break;
		}
	}
	
	dfs(1);
	//cout<<curmax<<" "<<curnode<<endl;
	par[curnode]=-1; curmax=0; dist[curnode]=0;
	dfs(curnode);
	//cout<<curmax<<" "<<curnode<<endl;
	vector<int> v;
	int cur=curnode;
	while(cur!=-1){
		v.pb(cur);
		mark[cur]=1;
		cur=par[cur];
	}
	for(int x:v){
		dfs2(x,-1,x);
	}
	
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		if(x==root[x]){
			printf("%lld\n",curmax);
		}
		else{
			ll y=root[x];
			//ll ans=a[x]+dist[x]-max(dist[y],curmax-dist[y])+dist[y];
			ll ans=a[x]+dist[x]-dist[y]+max(dist[y],curmax-dist[y]);
			//cout<<x<<" "<<a[x]<<" "<<dist[x]<<" "<<y<<" "<<dist[y]<<" "<<curmax-dist[y]<<endl;
			printf("%lld\n",ans);
		}
	}
	//for(int x:v) cout<<x<<" ";
	

    return 0;
}

