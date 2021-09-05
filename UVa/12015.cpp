#include <bits/stdc++.h>
using namespace std;
int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    string S[100];
    int T,V[1000];

    cin>>T;
    int serial[1000];

    for(int i=1;i<=T;i++)
    {
        int MAX;
        MAX=0;
        int k=1;
        for(int j=1;j<=10;j++)
        {
            cin>>S[j]>>V[j];

            if(V[j]>=MAX)
            {
                MAX=V[j];
            }
        }
        printf("Case #%d:\n",i);
        for(int x=1;x<=10;x++)
        {
            if(V[x]==MAX)
            {
                cout<<S[x]<<endl;
            }
        }
    }
    return 0;
}
