#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,N,K,P,i,j,x,A,B,result;
    cin>>T;
    for(x=1;x<=T;x++)
    {
        cin>>N>>K>>P;

        while(1)
        {
            A=K+P;
            if(A>N)
            {
                loop:
                B=A-N;
                if(B>N)
                {
                     A=B;
                     goto loop;
                }
            }
            else if(A<=N)
            {
                result=A;
                break;
            }
            if(B<=N)
            {
                result = B;
                break;
            }

        }
        printf("Case %d: %d\n",x,result);
    }
    return 0;
}
