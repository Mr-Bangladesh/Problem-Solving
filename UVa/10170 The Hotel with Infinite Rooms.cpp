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
    ll s=(n*(n+1))/2;
    return s;
}

int main()
{
    ll s,d;
    while(scanf("%lld %lld",&s,&d)!=EOF){
        ll x=(s*(s-1))/2;
        //cout<<x<<endl;
        ll k=d+x;
        ll l=1,r=1e9;
        while(l<=r){
            ll mid=(l+r)/2;
            if(f(mid)<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        printf("%lld\n",l);
    }

    return 0;
}


