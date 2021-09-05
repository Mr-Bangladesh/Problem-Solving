#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int n,m;
    int i,j;
    int C;
    int S;
    char A[100][100];
    char str[100][100];
    int field=1;
    while(cin>>n>>m){
            if(n==0 && m==0)
                break;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            C=0;
            if(A[i][j]=='*')
                str[i][j]=A[i][j];
            else if(A[i][j]=='.')
            {
                if(A[i-1][j-1]=='*')
                    C++;
                if(A[i][j-1]=='*')
                    C++;
                if(A[i+1][j-1]=='*')
                    C++;
                if(A[i+1][j]=='*')
                    C++;
                if(A[i+1][j+1]=='*')
                    C++;
                if(A[i][j+1]=='*')
                    C++;
                if(A[i-1][j+1]=='*')
                    C++;
                if(A[i-1][j]=='*')
                    C++;
                str[i][j]='0' + C;
            }
        }
    }
    printf("Field #%d:\n",field);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<str[i][j];
        }
        cout<<endl;
    }
    field++;
    }
    return 0;
}
