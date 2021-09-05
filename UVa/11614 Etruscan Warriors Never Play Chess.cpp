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
    int t;
    scanf("%d",&t);
    while(t--){
        ull n;
        scanf("%llu",&n);
        ull x=(sqrt(1+8*n)-1)/2;
        printf("%llu\n",x);
    }

    return 0;
}


