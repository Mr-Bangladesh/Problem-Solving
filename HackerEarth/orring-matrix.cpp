// Problem: Nag a ram
// Contest: HackerEarth - Data Structures - Hash Tables - Basics of Hash Tables
// URL: https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/orring-matrix/
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
#define maxn 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

ll f(string v){
	vector<int> s;
	int len=v.length();
	for(int i=0;i<len;i++){
		s.pb(v[i]-'a');
	}
	sort(s.begin(),s.end());
	s.resize(unique(s.begin(),s.end())-s.begin());
	ll sum=0;
	len=s.size();
	for(int i=0;i<len;i++){
		sum+=(1<<(s[i]));
	}
	return sum;
}

int main()
{
	//what the hell are youing? Think again before coding.
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		map<ll,vector<string> > cnt;
		for(int i=1;i<=n;i++){
			cin>>s;
			cnt[f(s)].pb(s);
		}
		for(auto it:cnt){
			sort(it.second.begin(),it.second.end());
			for(auto it1:it.second) cout<<it1<<" "; cout<<endl;
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