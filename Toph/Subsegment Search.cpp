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
#define maxn 1000005

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

ll hash1[maxn],hash2[maxn],power[maxn];
ll a[maxn],b[maxn];

map<ll,ll> val;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	
	power[0]=1;

	for(int i=1;i<maxn;i++){
		power[i]=(power[i-1]*base)%MOD;
	}
	
	int n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		
	}
	
	for(int i=1;i<=m;i++){
		cin>>b[i];
		
	}
	
	
	if(m==1){
		cout<<n<<endl;
		return 0;
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	
	for(int i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
		hash1[i]=((hash1[i-1]*base+a[i])%MOD+MOD)%MOD;
	}
	for(int i=1;i<m;i++){
		b[i]=b[i+1]-b[i];
		hash2[i]=((hash2[i-1]*base+b[i])%MOD+MOD)%MOD;
	}
	
	n--; m--;
	
	//for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
	//for(int i=1;i<=m;i++) cout<<b[i]<<" "; cout<<endl;
	
	int cnt=0;
	for(int i=1;i+m-1<=n;i++){
		ll cur=(hash1[i+m-1]-(hash1[i-1]*power[m])%MOD+MOD)%MOD;
		ll nxt=hash2[m];
		
		//cout<<cur<<" "<<nxt<<endl;
		
		if(cur==nxt) cnt++;
	}
	
	cout<<cnt<<endl;
	

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