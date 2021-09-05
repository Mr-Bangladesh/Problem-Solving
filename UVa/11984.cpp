#include <bits/stdc++.h>
using namespace std;
double Celcius(double F)
{
    double C;
    C=((F-32)/9.0)*5.0;
    return C;
}
double Farenheight(double C)
{
    double F;
    F=(9.0/5.0)*C + 32;
    return F;
}
int main()
{
    int T;
    double C,d,F;
    double sum;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>C>>d;
        sum=Farenheight(C)+d;
        printf("Case %d: %.2lf\n",i,Celcius(sum));
    }
    return 0;
}
