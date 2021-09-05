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
ll cnt[1000005];
int main()
{
    for(ll i=2;i<=1e6;i++){
        ll x=i*(i-1);
        cnt[i]=cnt[i-1]+x;
    }

    ll n,m;
    while(scanf("%lld %lld",&n,&m),n||m){
        ll x=n*m*(m-1);
        ll y=m*n*(n-1);
        ll a=min(n,m); ll b=max(n,m);
        ll z=cnt[a-1]*2;
        ll p=(a*(a-1))*(b-a+1);
        ll ans=x+y+(z+p)*2;
        printf("%lld\n",ans);
    }

    return 0;
}


