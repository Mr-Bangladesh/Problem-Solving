#include <bits/stdc++.h>
using namespace std;

int bigmod(int B,int P,int M)
{
    if(P==0)
        return 1;
    else if(P%2==0)
    {
        return bigmod((B*B)%M,P/2,M);
    }
    else
        return (B*bigmod((B*B)%M,(P-1)/2,M))%M;
}

int main()
{
    int B,P,M;
    while(cin>>B>>P>>M)
    {
        cout<<bigmod(B,P,M)<<endl;
    }
    return 0;
}
