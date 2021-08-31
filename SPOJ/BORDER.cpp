// Problem: Prefix borders
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/BORDER
// Memory Limit: 256 MB
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
#define base 313
#define base1 431
#define MOD1 999987337
#define maxm 200005
#define maxn 200005

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

int lps[maxn],par[maxn][21],depth[maxn];

void prefix_function(string pat,int n){
	lps[0]=0;
	for(int i=1;i<n;i++){
		int j=lps[i-1];
		while(j>0 && pat[i]!=pat[j])
			j=lps[j-1];
		if(pat[i]==pat[j]) j++;
		lps[i]=j;
	}
	for(int i=n;i>=1;i--){
		lps[i]=lps[i-1];
	}
	lps[0]=-1;
	depth[0]=0;
	for(int i=1;i<=n;i++){
		depth[i]=depth[lps[i]]+1;
	}
}

void pre(int n){
	for(int i=0;i<=n;i++){
		par[i][0]=lps[i];
	}
	par[0][0]=-1;
	for(int j=1;(1<<j)<=n;j++){
		for(int i=0;i<=n;i++){
			if(par[i][j-1]==-1) par[i][j]=-1;
			else par[i][j]=par[par[i][j-1]][j-1];
		}
	}
}

int query(int cur,int k){
	if(depth[cur]==k) return cur;
	if(depth[cur]<k) return -1;
	k++;
	for(int i=20;i>=0;i--){
		int nxt = par[cur][i];
		if(nxt!=-1 && depth[nxt]>=k){
			cur=nxt;
			k-=depth[nxt];
		}
	}
	return lps[cur];
}


int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		
		for(int i=0;i<=n;i++){
			lps[i]=0;
			depth[i]=0;
			for(int j=0;j<=20;j++) par[i][j]=-1;
		}
		
		string s;
		cin>>s;
		prefix_function(s,n);
		//for(int i=0;i<=n;i++) cout<<i<<" "<<lps[i]<<" "<<depth[i]<<endl;
		pre(n);
		while(q--){
			int d,k;
			cin>>d>>k;
			cout<<query(d,k)<<endl;
		}
	}
	

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