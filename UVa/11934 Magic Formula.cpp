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
ll f(ll x,ll a,ll b,ll c){
    return a*x*x+b*x+c;
}
int main()
{
    ll a,b,c,d,e;
    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e),a+b+c+d+e){
        int cnt=0;
        for(ll i=0;i<=e;i++){
            if(f(i,a,b,c)%d==0){
                //cout<<i<<" "<<a<<" "<<b<<" "<<c<<"   "<<f(i,a,b,c)<<endl;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}


