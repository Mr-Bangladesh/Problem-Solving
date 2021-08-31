// Problem: Playing with GCD
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/NAJPWG/
// Memory Limit: 1536 MB
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
#define maxn 100005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

ll phi[maxn];
void totient(){
	phi[1]=1;
	for(int i=2;i<maxn;i++) phi[i]=i-1;
	for(int i=2;i<maxn;i++){
		for(int j=i*2;j<maxn;j+=i){
			phi[j]-=phi[i];
		}
	}
}

int main()
{
	totient();
	for(int i=2;i<maxn;i++) phi[i]+=phi[i-1];
	
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		ll ans=(n*(n+1))/2-phi[n];
		printf("Case %d: %lld\n",cs++,ans);
	}

    return 0;
}

