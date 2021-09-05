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
    ll n;
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        ll x=sqrt(n);
        if(x*x!=n || n<9){
            cout<<0<<endl;
            continue;
        }
        ll candidate=x-2;
        ll ans=(candidate*(candidate+1))/2;
       cout<<ans<<endl;
    }

    return 0;
}


