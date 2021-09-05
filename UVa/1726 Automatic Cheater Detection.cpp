#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int level1[100000];
    int level2[100000];

    int L;
    int S;
    char A;

    int T,Q;

    scanf("%d",&T);

    for(int i=1;i<=T;i++)
    {
        scanf("%d",&Q);
        int len1=0;
        int len2=0;

        for(int i=1;i<=Q;i++)
        {
            scanf("%d %d %c",&L,&S,&A);

            if(S==0 && A=='i')
            {
                level1[len1]=L;
                len1++;
            }
            else if(S==1 && A=='c')
            {
                level2[len2]=L;
                len2++;
            }

        }
        int C=0;

        for(int k=0;k<len1;k++){
        for(int i=0;i<len2;i++)
        {
            if(level1[k]<level2[i]){
                C++;
                //cout<<level1[k]<<" "<<level2[i]<<endl;
            }
        }
        }
        printf("%d\n",C);



    }
    return 0;
}
