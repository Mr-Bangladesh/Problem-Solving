// Problem: Numbers Tell
// Contest: Toph
// URL: https://toph.co/p/numbers-tell
// Memory Limit: 1024 MB
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
#define MOD 1000000009
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		ll n,m;
		scanf("%lld %lld",&n,&m);
		ll d=(n/m);
		ll r=(n%m);
		r%=MOD;
		d--;
		ll x=d; ll y=d+1;
		if(x%2==0) x/=2;
		else if(y%2==0) y/=2;
		
		d=(d+1)%MOD;
		r=(r*d)%MOD;
		
		//cout<<" "<<x<<" "<<y<<" "<<d<<" "<<r<<endl;
		x%=MOD; y%=MOD; d%=MOD; m%=MOD;
		ll cur=(x*y)%MOD;
		cur=(cur*m)%MOD;
		cur=(cur+r)%MOD;
		printf("Case %d: %lld\n",cs++,cur);
	}

    return 0;
}

