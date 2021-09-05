#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
const ll maxx=100000000;
int status[(maxx>>5)+2];

bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N, int pos)
{
    return N=(N|(1<<pos));
}
vector<ll>Primes;
void sieve()
{
    ll i,j,sqrtN;
    sqrtN=ll(sqrt(maxx))+1;
    Primes.pb(2);
    for(int i=3;i<=maxx;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            Primes.pb(i);

            if(i<=sqrtN)
            for(j=i*i;j<=maxx;j+=(i<<1))
            {
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
}

ll bigmod(ll B,ll P,ll M){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=bigmod(B,P/2,M);
        return ((R%M)*(R%M))%M;
    }
    else{
        ll R=bigmod(B,P-1,M);
        return ((R%M)*(B%M))%M;
    }
}
bool miillerTest(ll d, ll n)
{
    ll a = 2 + rand() % (n - 4);
    ll x = bigmod(a, d, n);

    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}
bool isPrime(ll n, ll k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (ll i = 0; i < k; i++)
         if (!miillerTest(d, n))
              return false;

    return true;
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    sieve();

    scanf("%lld",&t);

    while(t--){
        scanf("%lld",&n);
        m=n;
        printf("%lld = ",n);

        if(isPrime(n,4)){
            printf("%lld\n",n);
            continue;
        }

        x=0;
        for(int i=0;i<Primes.size() && Primes[i]*Primes[i]<=n;i++){
            if(n%Primes[i]) continue;
            ll cnt=0;
            while(n%Primes[i]==0){
                cnt++;
                n/=Primes[i];
            }
            if(x) printf(" * ");
            printf("%lld",Primes[i]);
            if(cnt>1) printf("^%lld",cnt);
            x=1;
        }
        if(n!=1){
            if(n!=m) printf(" * ");
            printf("%lld",n);
        }
        printf("\n");
    }

    return 0;
}


