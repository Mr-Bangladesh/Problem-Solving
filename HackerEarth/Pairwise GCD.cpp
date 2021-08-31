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
ll const MAX = 1000000;
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
ll A[400005];
ll lim=400000;
void phi()
{
	for(ll i=2;i<=lim;i++) A[i]=i;
	for(ll x:Primes){
    	for(ll i=x;i<=lim;i+=x){
        	A[i]=(A[i]*(x-1))/x;
    	}
	}
}
ll res[400005];
void f(){
    res[1]=0;
    for(int i=1;i<=lim;i++){
        for(int j=i;j<=lim;j+=i){
            ll d=i*A[j/i];
            res[j]+=d;
        }
    }
    for(int i=2;i<=lim;i++){
        res[i]+=res[i-1];
    }
}

int main()
{
    sieve();
    phi();
    f();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",res[n]);
    }

    return 0;
}


