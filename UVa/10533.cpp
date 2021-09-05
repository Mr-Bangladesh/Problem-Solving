#include <bits/stdc++.h>
using namespace std;
typedef long long L;
#define MAX 100000

L primes[MAX];
void sieve()
{
    L A[MAX];
    for(int i=0;i<MAX;i++)
        A[i]=-1;
    for(int i=2;i<MAX;i++)
    {
        if(A[i]==-1)
        {
            for(int j=2;i*j<MAX;j++)
            {
                A[i*j]=0;
            }
        }
    }
    int k=0;
    for(int i=2;i<MAX;i++)
    {
        if(A[i]==-1)
        {
            primes[k]=i;
            k++;
        }
    }
}


L digitadd(L number)
{
    L add;
    add=0;
    while(number!=0)
    {
        add=add +(number%10);
        number=number/10;
    }
    return add;
}

bool isprime(L N)
{
    L i;
    bool check=true;
    for(i=2;i<=sqrt(N);i++)
    {
        if(N%i==0)
        {
            check=false;
            break;
        }
    }
    return check;
}


int main()
{
    sieve();
    L N,t1,t2,D;
    L counter;
    scanf("%lld",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%lld%lld",&t1,&t2);
            counter=0;
            for(int k=0;k<MAX;k++)
            {
                if(primes[k]>=t1 && primes[k]<=t2)
                {
                    D=digitadd(primes[k]);
                    if(isprime(D))
                        counter++;
                }
            }
        printf("%lld\n",counter);
    }
    return 0;
}
