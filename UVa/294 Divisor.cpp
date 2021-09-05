        ///Faizul
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <ll> primes;
#define MAX 10000000

bool A[MAX+100];

void sieve()
{
    primes.push_back(2);

    for(ll i=2;i<=MAX;i+=2)
        A[i]=1;
    for(ll i=3;i<=MAX;i+=2)
    {
        if(A[i]==0)
        {
            primes.push_back(i);
            for(ll j=i*2 ;j<=MAX;j+=i)
                A[j]=1;
        }
    }

}

ll power;

ll prime_factor(ll source)
{
    ll Count=0;

    ll sum=1;

    for(ll i=0;primes[i]*primes[i] <= source; i++)
    {
        if(source%primes[i])
        {
            continue;
        }
        power=0;

        while(source%primes[i]==0)
        {
            power++;
            source=source/primes[i];
        }
        sum=sum*(power+1);
    }

    if(source!=1)
    {
        sum=sum*2;
    }

    return sum;
}

int main()
{
    sieve();

    ll N,L,U;

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    scanf("%lld",&N);
    for(ll i=1;i<=N;i++)
    {
        scanf("%lld %lld",&L,&U);

        ll sum,M=0;
        ll number;

        for(ll i=L;i<=U;i++)
        {
            sum=prime_factor(i);
            if(sum>M)
            {
                M=sum;
                number=i;
            }
        }

        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,U,number,M);

    }


    return 0;
}
