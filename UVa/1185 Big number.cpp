#include <bits/stdc++.h>
using namespace std;
int digit(int N)
{
    if(N<0) return 0;
    else if(N<=1) return 1;

    double D=0;
    for(int i=2;i<=N;i++)
    {
        D+=log10(i);
    }

    return floor(D) + 1;

}

int main()
{
    int testcase;
    scanf("%d",&testcase);
    int A;
    for(int i=1;i<=testcase;i++)
    {
        scanf("%d",&A);
        int ans=digit(A);
        printf("%d\n",ans);
    }
    return 0;
}
