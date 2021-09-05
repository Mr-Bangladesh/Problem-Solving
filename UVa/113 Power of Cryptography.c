#include <stdio.h>
#include <math.h>
int main()
{
    double n,k,p;
    while(1)
    {
    scanf("%lf%lf",&n,&p);
    k=pow(p,1/n);
    printf("%.0lf\n",k);
    }
    return 0;
}
