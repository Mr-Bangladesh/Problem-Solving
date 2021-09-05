#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int level1[100];
    int level2[100];
    int L;
    int S;
    char A;

    int T,Q;

    scanf("%d",&T);

    for(int i=1;i<=T;i++)
    {
        scanf("%d",&Q);

        memset(level1,0,sizeof(level1));
        memset(level2,0,sizeof(level2));

        int len1=0;
        int len2=0;

        for(int i=1;i<=Q;i++)
        {
            scanf("%d %d %c",&L,&S,&A);

            if(S==0 && A=='i')
            {
                level1[L]++;
            }
            else if(S==1 && A=='c')
            {
                level2[L]++;
            }

        }
        int sum=0;

        for(int j=1;j<=10;j++)
        {
            for(int k=1;k<=10;k++)
            {
                if(j>k)
                {
                    sum+=level2[j]*level1[k];
                    //cout<<sum<<endl;
                }
            }
        }
        printf("%d\n",sum);



    }
    return 0;
}

