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
ll a[100003];
int main()
{
    ll lim=100000;
    for(ll i=1;i<=lim;i++){
        a[i]=a[i-1]+i;
    }
    ll n;
    while(scanf("%lld",&n)){
        if(n<0) break;
        ll i=lower_bound(a+1,a+lim,n)-a;
        //cout<<i<<endl;
        ll j=1;
        bool check=false;
        while(i<lim){
            ll g=a[i]-n;
            if(g==0){
                break;
            }
            ll x=lower_bound(a+1,a+i,g)-a;

            if(g==a[x]){
                //cout<<n<<" "<<g<<" "<<x<<" "<<i<<endl;
                j=x+1;
                break;
            }
            i++;
        }
        printf("%lld = %lld + ... + %lld\n",n,j,i);
    }

    return 0;
}


