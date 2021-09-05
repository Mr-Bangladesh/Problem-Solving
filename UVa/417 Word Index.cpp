#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S[100000];
    map<string,int> ans;

    int index=1;

    for(int i=1;i<=26;i++)
    {
        string A;
        A+=(i+96);
        ans[A]=index;
        S[index++]=A;

    }//printf("%c\n",i+96);

    for(int i=1;i<=26;i++)
    for(int j=i+1;j<=26;j++)
    {
        string A;
        A+=(i+96);
        A+=(j+96);
        ans[A]=index;
        S[index++]=A;
    }
        //printf("%c%c\n",i+96,j+96);

    for(int i=1;i<=26;i++)
    for(int j=i+1;j<=26;j++)
    for(int k=j+1;k<=26;k++)
    {
        string A;
        A+=(i+96);
        A+=(j+96);
        A+=(k+96);
        ans[A]=index;
        S[index++]=A;
    }// printf("%c%c%c\n",i+96,j+96,k+96);

    for(int i=1;i<=26;i++)
    for(int j=i+1;j<=26;j++)
    for(int k=j+1;k<=26;k++)
    for(int l=k+1;l<=26;l++)
    {
        string A;
        A+=(i+96);
        A+=(j+96);
        A+=(k+96);
        A+=(l+96);
        ans[A]=index;
        S[index++]=A;
    }//printf("%c%c%c%c\n",i+96,j+96,k+96,l+96);

    for(int i=1;i<=26;i++)
    for(int j=i+1;j<=26;j++)
    for(int k=j+1;k<=26;k++)
    for(int l=k+1;l<=26;l++)
    for(int m=l+1;m<=26;m++)
    {
        string A;
        A+=(i+96);
        A+=(j+96);
        A+=(k+96);
        A+=(l+96);
        A+=(m+96);
        ans[A]=index;
        S[index++]=A;
    }// printf("%c%c%c%c%c\n",i+96,j+96,k+96,l+96,m+96);

    //for(int i=1;i<index;i++) cout<<i<<" "<<S[i]<<endl;
    string input;
    while(cin>>input)
    {
        cout<<ans[input]<<endl;
    }

    return 0;

}
