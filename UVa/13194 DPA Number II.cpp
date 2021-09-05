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

ll pfactor[MAX];
ll power[MAX];
ll pfactor_size;

void prime_factor(ll N)
{
    ll Count=0;
    for(ll i=0;i<=MAX && primes[i]*primes[i]<=N;i++)
    {
        if(N%primes[i]==0)
        {
            pfactor[Count]=primes[i];
            Count++;
        }
        while(N%primes[i]==0)
        {
            power[Count-1]++;
            N=N/primes[i];
        }

    }
    if(N!=1)
    {
        pfactor[Count]=N;
        power[Count]=1;
        Count++;
    }
    pfactor_size=Count;
}

ll SOD(ll N)
{
    ll s=1;
    double sum=1;
    for(ll i=0;i<pfactor_size;i++)
    {
        sum=sum*((pow((double)pfactor[i],(double)power[i]+1)-1)/(pfactor[i]-1));
    }
    return (ll)sum;
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
        prime_factor(N);
        result=SOD(N)-N;
        //cout<<result+N<<endl;

        if(result<N)
        {
            printf("deficient\n");
        }
        else if(result==N)
            printf("perfect\n");
        else
            printf("abundant\n");

        memset(pfactor,0,sizeof(pfactor));
        memset(power,0,sizeof(power));

    }
    return 0;

}
