#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,X,Y,s,i;
    char A;
    cin>>T;
    for(X=1;X<=T;X++)
    {
        cin>>n;
        Y=0;
        for(i=1;i<=n;i++)
        {
            cin>>A;
            if(A=='W'||A=='D')
                Y=Y+1;
        }
        if(Y==n)
            printf("Case %d: Yay! Mighty Rafa persists!\n",X);
        else
            printf("Case %d: %d\n",X,Y);
    }
    return 0;
}
