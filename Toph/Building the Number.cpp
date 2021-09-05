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
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll x=bigmod(2,n,MOD);
        ll tmp=((x*(x-1))/2)%MOD;
        ll tmp2=bigmod(x,MOD-2,MOD);
        printf("%lld\n",(tmp*tmp2)%MOD);
    }

    return 0;
}


