#include <bits/stdc++.h>
using namespace std;

typedef long long L;

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    L N,M,A[1000],C,i,j;
    while(cin>>N>>M)
    {
        for(i=0;i<M;i++)
        {
            cin>>A[i];
        }
        C=0;
        for(i=1;i<=N;i++)
        {
            for(j=0;j<M;j++)
            {
                if(i%A[j]==0)
                {

                    C++;
                    break;
                }
            }
        }
        cout<<N-C<<endl;
    }
    return 0;
}
