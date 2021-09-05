#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,height;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        queue <int> H;
        for(int j=1;j<=n;j++)
        {
            cin>>height;
            H.push(height);
        }
        int C=0;
        int position=1;
        int N=0;
        for(int j=1;j<=n;j++)
        {
            if(H.front()==position)
            {
              position++;
              //N++;
              H.pop();
            }

            else if(H.front()!=position)
            {
                H.pop();
                C++;
            }
        }
            printf("Case %d: %d\n",i,C);

    }
    return 0;
}
