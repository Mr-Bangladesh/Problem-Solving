#include <bits/stdc++.h>
using namespace std;

typedef long long L;

L divisors(L number)
{
    L sum;
    L divisor[1000];
    L s;
    int j=1;
    sum=1;
    for(int i=2;i<=sqrt(number);i++)
    {
        if(number%i==0)
        {
            s=number/i;
            sum=sum+i+s;
            if(i==s)
            {
                sum=sum-s;
            }
        }
    }

    return sum;

}
int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    L sum,t,N;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%lld",&N))
    {
        if(N==0)
            break;
        if(N==1)
            printf("%5lld  DEFICIENT\n",N);
        else{
        sum=divisors(N);

        if(N==sum)
            printf("%5lld  PERFECT\n",N);
        else if(N>sum)
            printf("%5lld  DEFICIENT\n",N);
        else if(N<sum)
            printf("%5lld  ABUNDANT\n",N);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
