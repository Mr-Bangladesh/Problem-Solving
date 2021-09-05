#include <bits/stdc++.h>
using namespace std;

int juice(int a)
{
    double S;
    S=ceil(double(a)/60.0);
    return S*15;
}

int miles(int a)
{
    double S;
    S=ceil(double(a)/30.0);
    return S*10;
}

int main()
{
    int T,N,A[10000];
    cin>>T;
    int J,M;
    int S1,S2;
    int Duration[10000];
    for(int i=1;i<=T;i++)
    {
        cin>>N;
        J=0;
        M=0;
        for(int j=0;j<N;j++)
        {
            cin>>Duration[j];
        }
        J=0;
        M=0;
        for(int j=0;j<N;j++)
        {
            S1=miles(Duration[j]+1);
            S2=juice(Duration[j]+1);
            J=J+S2;
            M=M+S1;
        }
        if(J>M)
            printf("Case %d: Mile %d\n",i,M);
        else if(J<M)
            printf("Case %d: Juice %d\n",i,J);
        else
            printf("Case %d: Mile Juice %d\n",i,M);
    }
    return 0;
}
