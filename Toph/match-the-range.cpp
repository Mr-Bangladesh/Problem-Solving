// Problem: Match the Range
// Contest: Toph
// URL: https://toph.co/p/match-the-range
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
#define MOD2 999987323
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 200005
#define base 89
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	
	
	int n,q;
	scanf("%d %d",&n,&q);
	int a[n+1];
	
	ull h[n+1],h2[maxn];
	h[0]=h2[0]=0;
	
	for(int i=1;i<=1e5;i++){
		h2[i]=rng();
	}
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		h[i]=(h[i-1]+h2[a[i]]);
	}
	int l,r,x,y;
	while(q--){
		scanf("%d %d %d %d",&l,&r,&x,&y);
		int cur=(h[r]-h[l-1]);
		int next=(h[y]-h[x-1]);
		if(cur==next){
			printf("Yes\n");
		}
		else printf("No\n");
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