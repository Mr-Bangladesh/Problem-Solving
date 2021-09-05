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
    int n;
    while(scanf("%d",&n),n){
        int x=__builtin_popcount(n);
        if(n==((1LL<<x)-1)){
            printf("Bob\n");
        }
        else{
            printf("Alice\n");
        }
    }

    return 0;
}


