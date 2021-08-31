// Problem: Special palindromes
// Contest: HackerEarth - Algorithms - String Algorithms - String Searching
// URL: https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/special-palindrome-11f52457/
// Memory Limit: 256 MB
// Time Limit: 500 ms
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

int n;
char str[1005];

vector<int> prefix_function(){
	vector<int> lps(n);
	lps[0]=0;
	for(int i=1;i<n;i++){
		int j=lps[i-1];
		while(j>0 && str[i]!=str[j]){
			j=lps[j-1];
		}
		if(str[i]==str[j]) j++;
		
		lps[i]=j;
	}
	return lps;
}

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",str);
		vector<int> lps=prefix_function();
		int ans=n;
		for(int x:lps){
			if(x) ans++;
		}
		
		printf("%d\n",ans);
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