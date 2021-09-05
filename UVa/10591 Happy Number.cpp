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
ll g(ll n){
    ll sum=0;
    while(n){
        ll r=n%10;
        sum+=(r*r);
        n/=10;
    }
    return sum;
}
map<ll,bool> mark;
ll f(ll n){
    //cout<<n<<endl;
    if(n==1) return 1;
    if(mark.find(n)!=mark.end()) return 0;
    mark[n]=1;
    return f(g(n));
}

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        mark.clear();
        if(f(n)){
            printf("Case #%d: %lld is a Happy number.\n",cs++,n);
        }
        else{
            printf("Case #%d: %lld is an Unhappy number.\n",cs++,n);
        }
    }

    return 0;
}

