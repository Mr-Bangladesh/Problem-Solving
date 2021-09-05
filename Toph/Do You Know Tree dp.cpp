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

pair<ll,ll> in[maxn];
ll ans[maxn];

void dfs(int u,int par){
	ll mx1=0,mx2=0;
	for(auto it:g[u]){
		int v=it.first; ll w=it.second;
		if(v==par) continue;
		dfs(v,u);
		ll cur=w+in[v].first;
		if(cur>=mx1){
			mx2=mx1;
			mx1=cur;
		}
		else if(cur>mx2){
			mx2=cur;
		}
	}
	in[u]={mx1,mx2};
}

void dfs2(int u,int par,ll cost){
	ll a=in[u].first; ll b=max(cost,in[u].second);
	ans[u]=a+b;
	for(auto it:g[u]){
		int v=it.first; ll w=it.second;
		if(v==par) continue;
		if(w+in[v].first==a){
			dfs2(v,u,b+w);
		}
		else{
			dfs2(v,u,max(a,cost)+w);
		}
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
	dfs(1,-1);
	dfs2(1,-1,0);
	
	// for(int i=1;i<=n;i++){
		// cout<<i<<" "<<in[i]<<" "<<out[i]<<endl;
	// }
	
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		printf("%lld\n",ans[x]);
	}

    return 0;
}