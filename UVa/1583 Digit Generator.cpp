#include <bits/stdc++.h>
using namespace std;

int length(int N)
{
    int C=0;

    while(N!=0)
    {
        int r=N%10;
        C++;
        N=N/10;
    }
    return C*9;
}

int digit(int N)
{
    int sum=N;
    while(N!=0)
    {
        sum+=(N%10);
        N=N/10;
    }
    return sum;
}

int main()
{
    int T,N;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>N;
        int L=N-length(N);
        bool check=false;
        for(int j=L;j<N;j++)
        {
            if(digit(j)==N)
            {
                check=true;
                cout<<j<<endl;
                break;
            }
        }
        if(check==0)
            cout<<0<<endl;
    }
    return 0;
}
