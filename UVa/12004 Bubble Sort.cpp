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
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        if(n==2){
            printf("Case %d: 1/2\n",cs++);
        }
        else{
            printf("Case %d: %lld\n",cs++,(n*(n-1))/2);
        }
    }

    return 0;
}


