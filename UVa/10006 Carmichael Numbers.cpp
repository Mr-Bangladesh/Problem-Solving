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

vector<ll> Primes;
ll const MAX = 100000000;
bitset<MAX> prime;
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for(ll i = 2; i * i < MAX; ++i)
        if(prime[i])
            for(ll j = i * i; j < MAX; j += i)
                prime[j] = 0;
    for(int i=2;i<=MAX;i++){
        if(prime[i]) Primes.pb(i);
    }
}

int main()
{
    sieve();
    int n;
    while(scanf("%d",&n),n){
        if(!binary_search(Primes.begin(),Primes.end(),n)){
            int cnt=0;
            int m=n;
            for(int i=0;Primes[i]*Primes[i]<=n;i++){
                if(n%Primes[i]) continue;
                cnt++;
                while(n%Primes[i]==0){
                    n/=Primes[i];
                }
            }
            if(n!=1){
                cnt++;
            }
            if(cnt>=3){
                printf("The number %d is a Carmichael number.\n",m);
            }
            else{
                printf("%d is normal.\n",m);
            }
        }
        else{
            printf("%d is normal.\n",n);
        }
    }

    return 0;
}


