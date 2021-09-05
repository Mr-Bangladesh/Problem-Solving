#include <bits/stdc++.h>
using namespace std;
int main()
{

    int T,n,H[100000],S;
    cin>>T;
    for(int i=1;i<=T;++i)
    {
        cin>>n;
        for(int j=0;j<n;++j)
        {
            cin>>H[j];
        }
        S=1;
        for(int j=0;j<n;++j)
        {
            if(H[j]==S)
                ++S;
        }
        printf("Case %d: %d\n",i,n-(S-1));
    }
    return 0;
}
