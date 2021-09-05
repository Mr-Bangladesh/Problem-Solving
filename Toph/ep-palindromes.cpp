// Problem: EP-Palindromes
// Contest: Toph
// URL: https://toph.co/p/ep-palindromes
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
#define maxn 2000005
#define base 313
#define base1 431
#define MOD1 999987337
#define maxm 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

ll power[maxn],power1[maxn];

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	power[0]=1; power1[0]=1;
	for(int i=1;i<maxn;i++){
		power[i]=(power[i-1]*2LL)%MOD;
		power1[i]=(power1[i-1]*2LL)%MOD1;
	}
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[n+2];
		ll Hash[n+2],Hash1[n+2];
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			Hash[i]=power[a[i]];
			Hash1[i]=power1[a[i]];
			//cout<<i<<" "<<a[i]<<" "<<Hash[i]<<endl;
		}
		map< pair<ll,ll> ,ll> cnt; cnt[{0,0}]=1;
		ll cur=0,ans=0,cur1=0;
		for(int i=1;i<=n;i++){
			cur^=Hash[i];
			cur1^=Hash1[i];
			//cout<<i<<" "<<cur<<endl;
			if(cnt.find({cur,cur1})!=cnt.end()){
				ans+=cnt[{cur,cur1}];
			}
			cnt[{cur,cur1}]++;
		}
		printf("Case %d: %lld\n",cs++,ans);
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