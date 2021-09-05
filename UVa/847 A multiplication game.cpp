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
    while(scanf("%lld",&n)!=EOF){
        int cnt=1;
        ll cur=1;
        while(cur<n){
            if(cnt%2){
                cur*=9;
            }
            else{
                cur*=2;
            }
            //if(cur>=n) break;
            cnt++;
        }
        if(cnt%2==0){
            printf("Stan wins.\n");
        }
        else{
            printf("Ollie wins.\n");
        }
    }

    return 0;
}


