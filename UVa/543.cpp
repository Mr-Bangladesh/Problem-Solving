#include <bits/stdc++.h>
using namespace std;
typedef long long L;
#define MAX 1000006
L prime[MAX];
L A[MAX];
L n,sum;
L i,j,k;
void seive()
{
    for(i=0;i<MAX;i++)
        A[i]=-1;
    for(i=2;i<MAX;i++)
    {
        if(A[i]==-1)
        {
            for(j=2;i*j<MAX;j++)
            {
                A[i*j]=0;
            }
        }
    }
    k=0;
    for(i=2;i<MAX;i++)
    {
        if(A[i]!=0)
        {
            prime[k]=i;
            k++;
        }
    }
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

    L m;
    L a,b,j,sub,sum;
    seive();
    while(cin>>n)
    {
        if(n==0)
            break;
        j=0;
        bool check=false;
        while(1)
        {
            sub=n-prime[j];
            if(sub==0)
            {
                check=false;
                break;
            }
            else if(isprime(sub))
            {
                a=prime[j];
                b=sub;
                check=true;
                break;
            }
            else
                j++;
        }

        if(check==true)
            printf("%lld = %lld + %lld\n",n,a,b);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}


