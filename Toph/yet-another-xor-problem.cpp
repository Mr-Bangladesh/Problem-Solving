// Problem: Yet Another XOR Problem
// Contest: Toph
// URL: https://toph.co/p/yet-another-xor-problem
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
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
#define base 313
#define base1 431
#define MOD1 999987337
#define maxm 200005
#define maxn 500005
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

int a[maxn];
vector<int> g[maxn];
int ans=0;
#define MAX_NODE 10000005
int root,indx,trie[MAX_NODE][3],endpoint[MAX_NODE],substrcnt[MAX_NODE][3];
struct Trie{
	Trie(){
		root=indx=0;
	    for(int i=0;i<2;i++){
	        trie[root][i]=-1;
	    }
	}
	void Add(int n){
	    int now=root;
	    for(int i=30;i>=0;i--){
	    	int id=(n>>i)&1;
	    	if(trie[now][id]==-1){
	    		trie[now][id]=++indx;
	    		for(int j=0;j<2;j++){
	    			trie[indx][j]=-1;
	    		}
	    	}
	    	substrcnt[now][id]++;
	    	now=trie[now][id];
	    }
	    endpoint[now]++;
	}
	void Delete(int n){
	    int now=root;
	    for(int i=30;i>=0;i--){
	    	int id=(n>>i)&1;
	    	substrcnt[now][id]--;
	    	now=trie[now][id];
	    }
	    endpoint[now]--;
	}
	int Query(int n){
		int res=0;
		int now=root;
		for(int i=30;i>=0;i--){
			int id=(n>>i)&1;
			if(trie[now][id^1]!=-1 && substrcnt[now][id^1]>0){
				res|=(1<<i);
				now=trie[now][id^1];
			}
			else{
				now=trie[now][id];
			}
		}
		return res;
	}
	void dfs(int u,int par){
		Add(a[u]);
		if(u!=1){
			int cur=Query(a[u]);
			ans=max(ans,cur);
		}
		for(int v:g[u]){
			if(v==par) continue;
			dfs(v,u);
		}
		Delete(a[u]);
	}
};

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	
	Trie t=Trie();
	
	t.dfs(1,-1);
	
	printf("%d\n",ans);

    return 0;
    //you should actually read the stuff at the bottom
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smooth instead of nothing and stay organized
	* don't get stuck on one approach, try another
	* don't waste time in one problem, try another
	* check PI value acos(-1.0)
*/