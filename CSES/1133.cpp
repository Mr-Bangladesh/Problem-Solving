// Problem: Tree Distances II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1133
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
#define maxn 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

vector<int> g[maxn];
ll in[maxn],out[maxn],sz[maxn];

void dfs(int u,int par){
	sz[u]=1;
	for(int v:g[u]){
		if(v==par) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		in[u]+=(in[v]+sz[v]);
	}
}
int n;

void dfs2(int u,int par){ //correct
	
	ll sum=0;
	for(int v:g[u]){
		if(v==par) continue;
		sum+=(in[v]+(sz[v]*2));
	}
	
	for(int v:g[u]){
		if(v==par) continue;
		ll cur=out[u]+(n-sz[u]+1)+(sum-(in[v]+sz[v]*2));
		out[v]=cur;
		dfs2(v,u);
	}
}

int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	
	dfs(1,0);
	dfs2(1,0);
	
	for(int i=1;i<=n;i++){
		printf("%lld ",in[i]+out[i]);
	}

    return 0;
}

