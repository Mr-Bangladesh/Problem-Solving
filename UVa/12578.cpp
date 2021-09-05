#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)

double area(double L)
{
    double W=(6.0/10.0)*L;
    return L*W;
}
double red(double L)
{
    double R=(1.0/5.0)*L;
    return PI*R*R;
}
int main()
{
    int T;
    double L;
    double A,R,G;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>L;
        A=area(L);
        R=red(L);
        G=A-R;
        printf("%.2lf %.2lf\n",R,G);

    }
    return 0;
}
