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

ll f(ll n){
    return (n*(n+1))/2;
}

int main()
{
    ll n;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        ll m=abs(n);
        ll l=1,r=100000;
        while(l<=r){
            ll mid=(l+r)/2;
            if(f(mid)<m){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ll s=f(l);
        ll g=s-m;
        if(g%2==0){
            printf("%lld\n",l);
        }
        else{
            if(l%2==0){
                l++;
            }
            else{
                l+=2;
            }
            printf("%lld\n",l);
        }
        if(t) printf("\n");
    }

    return 0;
}
