/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll f(ll n,ll k){
    if(n==1) return 1;
    return (f(n-1,k)+k-1)%n+1;
}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        ll n,k;
        scanf("%lld %lld",&n,&k);
        ll ans=f(n,k);
        printf("Case %d: %lld\n",cs++,ans);
    }

    return 0;
}



