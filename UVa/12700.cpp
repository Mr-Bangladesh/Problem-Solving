#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    int T,N,i,j,sum,B,W,M,S,x;
    char A;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>N;
        B=0;W=0;M=0;S=0;
        for(x=1;x<=N;x++)
        {
            cin>>A;
            if(A=='B')
                B++;
            else if(A=='W')
                W++;
            else if(A=='T')
                M++;
            else if(A=='A')
                S++;
        }
        if(M==N)
            printf("Case %d: DRAW %d %d\n",i,B,N);
        else if(B==N)
            printf("Case %d: BANGLAWASH\n",i);
        else if(W==N)
            printf("Case %d: WHITEWASH\n",i);
        else if(S==N)
            printf("Case %d: ABANDONED\n",i);
        else if(B>W)
            printf("Case %d: BANGLADESH %d - %d\n",i,B,W);
        else if(W>B)
            printf("Case %d: WWW %d - %d\n",i,W,B);
        else if(W==B)
            printf("Case %d: DRAW %d %d\n",i,B,W);
        //else if(M==N)

    }
    return 0;
}
