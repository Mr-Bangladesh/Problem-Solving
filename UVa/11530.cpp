#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,i,j,len,sum,s;
    string A;
    cin>>T;
    getchar();
    for(i=1;i<=T;i++)
    {
        getline(cin,A);
        len=A.length();
        sum=0;
        for(j=0;j<len;j++)
        {
            if(A[j]=='a')
                s=1;
            else if(A[j]=='b')
                s=2;
            else if(A[j]=='c')
                s=3;
            else if(A[j]=='d')
                    s=1;
            else if(A[j]=='e')
            s=2;
            else if(A[j]=='f')
            s=3;
            else if(A[j]=='g')
            s=1;
            else if(A[j]=='h')
            s=2;
            else if(A[j]=='i')
            s=3;
            else if(A[j]=='j')
            s=1;
            else if(A[j]=='k')
            s=2;
            else if(A[j]=='l')
            s=3;
            else if(A[j]=='m')
            s=1;
            else if(A[j]=='n')
            s=2;
            else if(A[j]=='o')
                    s=3;
            else if(A[j]=='p')
            s=1;
            else if(A[j]=='q')
            s=2;
            else if(A[j]=='r')
            s=3;
            else if(A[j]=='s')
            s=4;
            else if(A[j]=='t')
            s=1;
            else if(A[j]=='u')
            s=2;
            else if(A[j]=='v')
            s=3;
            else if(A[j]=='w')
            s=1;
            else if(A[j]=='x')
                    s=2;
            else if(A[j]=='y')
            s=3;
            else if(A[j]=='z')
            s=4;
            else if(A[j]==32)
                s=1;
        sum=sum+s;
        }
        printf("Case #%d: %d\n",i,sum);
    }
}
