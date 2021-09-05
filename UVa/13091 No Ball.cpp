#include <bits/stdc++.h>
using namespace std;
int main()
{

    //freopen("1.txt","r",stdin);

    int T;

    cin>>T;
    for(int i=1;i<=T;i++)
    {
        string S[10];
        for(int j=0;j<5;j++)
        {
            cin>>S[j];
        }

        string S1[10];

        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(S[j][k]=='|' || S[j][k]=='>' || S[j][k]=='<') S1[j]+=S[j][k];
            }
        }

        bool check=false;

        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(S1[j][k]=='|' && S1[j][k+1]=='>') {check=true;break;}

                else if(S1[j][k]=='<' && S1[j][k+1]=='|') {check=true; break;}
            }
        }

        if(check==true) printf("Case %d: No Ball\n",i);

        else printf("Case %d: Thik Ball\n",i);


    }

    return 0;
}
