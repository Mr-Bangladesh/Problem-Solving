#include <stdio.h>
int uva(int n)
{
    int sum=1;
    long long x,k,max;
    while(n!=1)
    {
        if(n%2==0)
        {
            x=n/2;
        }
        else
        {
            x=3*n+1;
        }
        sum=sum+1;
        n=x;
    }

    return sum;
}
int main()
{
    long long i,j,n;
    int s,max=0;
    while(scanf("%lld%lld",&i,&j)!=EOF)
    {
        max=0;
        if(i<=j){
    for(n=i;n<=j;n++)
    {
        s=uva(n);
        if(s>max)
    {
        max=s;
    }
    }
    printf("%lld %lld %d\n",i,j,max);}
    else if(i>j){
        for(n=j;n<=i;n++)
        {
            s=uva(n);
            if(s>max)
            {
                max=s;
            }
        }
        printf("%lld %lld %d\n",i,j,max);
    }

    }
    return 0;
}
