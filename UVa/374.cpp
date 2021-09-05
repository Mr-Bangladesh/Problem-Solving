#include <bits/stdc++.h>
using namespace std;

int bigmod(int B,int P,int M)
{
    if(P==0)
        return 1;
    else if(P%2==0)
    {
        int R=bigmod(B,P/2,M);
        return ((R%M)*(R%M))%M;
    }
    else
    {
        int R=bigmod(B,P-1,M);
        return ((R%M)*(B%M))%M;
    }
}

int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int B,P,M;

    while(cin>>B>>P>>M)
    {
        cout<<bigmod(B,P,M)<<endl;
    }
    return 0;
}
