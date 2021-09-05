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
    while(scanf("%lld",&n),n){
        if(n==1){
            printf("1 1\n");
            continue;
        }
        ll x=1,y=1;
        ll i=1;
        while(1){
            if(i*i>=n){
                x=i;
                y=i;
                break;
            }
            i++;
        }
        ll up=x*x,lo=(x-1)*(x-1)+1;
        ll center=(up+lo)/2;
        ll d=abs(center-n);
        if(n==center){
            printf("%lld %lld\n",x,y);
        }
        else if(n>center){
            if(x%2){
                printf("%lld %lld\n",x-d,x);
            }
            else{
                printf("%lld %lld\n",x,x-d);
            }
        }
        else{
            if(x%2){
                printf("%lld %lld\n",x,x-d);
            }
            else{
                printf("%lld %lld\n",x-d,x);
            }
        }
    }

    return 0;
}


