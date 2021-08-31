// Problem: LCM Sum
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/LCMSUM/
// Memory Limit: 1536 MB
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

#define MAX 1000001
ll phi[MAX],res[MAX];
void computeTotient(){
    phi[1] = 1;
    for (ll i=2; i<MAX; i++){
        if (!phi[i]){
            phi[i] = i-1;
            for (ll j = (i<<1); j<MAX; j+=i){
                if (!phi[j]){
                    phi[j] = j;
                }
                phi[j] = (phi[j]/i)*(i-1);
            }
        }
    }
}
void precal(){
	for(ll i=1;i<MAX;i++){
		for(ll j=i;j<MAX;j+=i){
			res[j]+=i*phi[i];
		}
	}
}

int main()
{
	computeTotient();
	precal();
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		//cout<<n<<" "<<res[n]<<endl;
		ll ans=((res[n]+1)*n)/2;
		printf("%lld\n",ans);
	}

    return 0;
}

