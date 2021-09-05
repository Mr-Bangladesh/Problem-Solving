#include <bits/stdc++.h>
using namespace std;
int main()
{
    int S,A[14];
    int N;
    cin>>S;
    for(int i=1;i<=S;i++)
    {
        for(int j=0;j<13;j++)
        {
            cin>>A[j];
        }
        int check=1;
        for(int j=0;j<13;j++)
        {
            if(A[j]<=0)
            {
                check=0;
            }
        }
        if(check==1)
            printf("Set #%d: Yes\n",i);
        else
            printf("Set #%d: No\n",i);
    }
    return 0;
}
