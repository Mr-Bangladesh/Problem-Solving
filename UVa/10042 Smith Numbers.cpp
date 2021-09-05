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
int f(int n){
    int s=0;
    while(n){
        s+=(n%10);
        n/=10;
    }
    return s;
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--){
        int a;
        scanf("%d",&a);
        int m=a+1;
        while(1){
            int sum=0;
            int n=m;
            int cnt=0;
            for(int i=0;Primes[i]*Primes[i]<=n;i++){
                if(n%Primes[i]) continue;
                //cnt++;
                while(n%Primes[i]==0){
                    n/=Primes[i];
                    cnt++;
                    //cout<<Primes[i]<<endl;
                    sum+=f(Primes[i]);
                }
            }
            if(n!=1){
                sum+=f(n);
                cnt++;
                //cout<<n<<endl;
            }
            //cout<<m<<" "<<f(m)<<" "<<sum<<endl;
            if(cnt>1 && f(m)==sum){
                printf("%d\n",m);
                break;
            }
            m++;
        }
    }

    return 0;
}


