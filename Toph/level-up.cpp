// Problem: Level Up
// Contest: Toph
// URL: https://toph.co/p/level-up
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
#define maxn 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

ll bigmod(ll B,ll P,ll M){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=bigmod(B,P/2,M);
        return ((R%M)*(R%M))%M;
    }
    else{
        ll R=bigmod(B,P-1,M);
        return ((R%M)*(B%M))%M;
    }
}

int main()
{
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		ll n,a,b,l;
		scanf("%lld %lld %lld %lld",&n,&a,&b,&l);
		l%=MOD;
		a%=MOD;
		b%=MOD;
		
		ll ans=bigmod(n-1,l-3,MOD);
		ll x=(l-b)%MOD; ll y=(l-a-1)%MOD;
		x=(x+y)%MOD;
		ans=(ans*x)%MOD;
		
		//cout<<l-3<<" "<<n-1<<" "<<l-b<<" "<<l-a-1<<endl;
		
		printf("Case %d: %lld\n",cs++,ans);
	}

    return 0;
}

