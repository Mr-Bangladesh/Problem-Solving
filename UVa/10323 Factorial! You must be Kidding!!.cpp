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

ll upper=6227020800;
ll lower=10000;

int main()
{
    ll a[30];
    a[0]=1;
    for(int i=1;i<=15;i++) a[i]=a[i-1]*i;

    ll n;
    while(scanf("%lld",&n)!=EOF){
        if(n>13) printf("Overflow\n");
        else if(n<8) printf("Underflow!\n");
        else printf("%lld\n",a[n]);
    }

    return 0;
}

