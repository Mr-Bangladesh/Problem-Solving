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
#define maxn 100005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

vector< pair<int,int> > g[maxn];
int val[maxn],T[maxn],depth[maxn];

void dfs(int u,int p){
	for(auto v:g[u]){
		if(v.first==p) continue;
		depth[v.first]=depth[u]+1;
		val[v.first]=v.second;
		
		T[v.first]=u;
		
		dfs(v.first,u);
	}
}
int par[maxn][20],curgcd[maxn][20];
void init(int n){
	for(int i=1;i<=n;i++){
		g[i].clear();
		T[i]=-1;
		val[i]=depth[i]=0;
		for(int j=0;(1<<j)<=n;j++){
			par[i][j]=-1;
			curgcd[maxn][20]=0;
		}
	}
}

void build(int n){
	for(int i=1;i<=n;i++){
		par[i][0]=T[i];
		curgcd[i][0]=val[i];
	}
	
	
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			if(par[i][j-1]!=-1){
				par[i][j]=par[par[i][j-1]][j-1];
				curgcd[i][j]=__gcd(curgcd[i][j-1],curgcd[par[i][j-1]][j-1]);
			}
		}
	}
}

int main()
{
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		int n,x,y,w,q;
		scanf("%d",&n);
		init(n);
		for(int i=1;i<n;i++){
			scanf("%d %d %d",&x,&y,&w);
			g[x].pb(mp(y,w));
			g[y].pb(mp(x,w));
		}
		dfs(1,-1);
		build(n);
		// for(int i=1;i<=n;i++){
			// cout<<i<<"  ";
			// for(int j=0;(1<<j)<=n;j++) cout<<par[i][j]<<" "; cout<<endl;
		// }
		
		scanf("%d",&q);
		printf("Case %d:\n",cs++);
		while(q--){
			scanf("%d %d",&x,&y);
			
			int res=0;
			int lg=log2(depth[x]);
			for(int i=lg;i>=0;i--){
				if(par[x][i]==-1) continue;
				if(curgcd[x][i]%y==0){
					//cout<<x<<" "<<par[x][i]<<endl;
					x=par[x][i];
				}
			}
			printf("%d\n",x);
		}
	}
	

    return 0;
}

