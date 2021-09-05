#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100000

vector <ll> primes;

bool A[MAX+100];

void sieve()
{
    primes.push_back(2);

    for(ll i=2;i<=MAX;i+=2)
        A[i]=1;
    for(ll i=3;i<=MAX;i++)
    {
        if(A[i]==0)
        {
            primes.push_back(i);
            for(ll j=i*i;j<=MAX;j+=i*2)
                A[j]=1;
        }
    }

}


ll pdivisor[MAX];
ll len;

void prime_factor(ll N)
{
    ll Count=0;
    for(ll i=0;primes[i]*primes[i]<=N;i++)
    {
        if(N%primes[i]==0)
        {
            pdivisor[Count]=primes[i];
            Count++;
        }
        while(N%primes[i]==0)
        {
            //power[Count-1]++;
            N=N/primes[i];
        }
    }
    if(N!=1)
    {
        pdivisor[Count]=N;
        Count++;
    }
    len=Count;
}


ll coprime(ll N)
{
    double sum=N;
    for(ll i=0;i<len;i++)
    {
        double X=double(pdivisor[i]-1)/(double)pdivisor[i];
        //cout<<sum<<endl;
        sum=sum*X;
    }
    return ll(sum);
}

int main()
{
    sieve();
    ll N;
    while(scanf("%lld",&N))
    {
        if(N==0) break;

        prime_factor(N);
        cout<<coprime(N)<<endl;

    }
    return 0;
}
