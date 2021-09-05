#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 1000000

vector <ll> primes;

int A[MAX+100];

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

ll prime_factor(ll N)
{
    ll ret=1;
    for(ll i=0;i<=MAX && primes[i]*primes[i]<=N;i++)
    {
        if(N%primes[i]!=0)
        {
            continue;
        }
        ll P=primes[i];
        ll sum=P;

        while(N%primes[i]==0)
        {
            N=N/primes[i];
            sum=sum*P;
        }
        ret=ret*(sum-1)/(P-1);


    }
    if(N!=1)
    {
        ret=ret*(N+1);
    }
    return ret;
}

int main()
{
    sieve();

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    ll N,t,result;

    scanf("%lld",&t);

    for(ll i=1;i<=t;i++)
    {
        scanf("%lld",&N);
        if(N==0)
        {
            printf("perfect\n");
            continue;
        }
        result=prime_factor(N)-N;
        //cout<<result+N<<endl;
        //result=SOD(N)-N;

        if(result<N)
        {
            printf("deficient\n");
        }
        else if(result==N)
            printf("perfect\n");
        else
            printf("abundant\n");


    }
    return 0;

}
