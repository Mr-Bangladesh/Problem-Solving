#include <bits/stdc++.h>
using namespace std;

string stringreverse(string S)
{
    string rev;
    int len=S.length();
    for(int i=len-1;i>=0;i--)
        rev+=S[i];
    return rev;
}

string onetoten(int N,int to)
{
    int r;
    string S;

    while(N!=0)
    {
        r=N%to;
        S+=(r+48);
        N=N/to;
    }

    return stringreverse(S) ;
}

int main()
{
    int number,from,to;

    while(scanf("%d %d %d",&number,&from,&to)!=EOF)
    {
        cout<<onetoten(number,to)<<endl;
    }
}
