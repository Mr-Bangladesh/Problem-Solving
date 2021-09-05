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

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll ans=1;
        ll d=n/2;
        for(ll i=1;i<=d;i++){
            ans=ans*5;
        }
        if(ans==1) ans=0;
        if(n%2) ans++;
        printf("%lld\n",ans);
    }

    return 0;
}


