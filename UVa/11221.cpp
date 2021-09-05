#include <bits/stdc++.h>
using namespace std;

string perfectstring(string A)
{
    int len=A.length();
    string B;
    for(int i=0;i<len;i++)
    {
        if((A[i]>=65 && A[i]<=90)||(A[i]>=97 && A[i]<=122))
            B+=A[i];
    }
    return B;
}

int perfectsquare(int N)
{
    int M=sqrt(N);
    if(M*M == N)
        return true;
    else
        return false;
}

string stringreverse(string S)
{
    string rev;
    int len=S.length();
    for(int i=len-1;i>=0;i--)
        rev+=S[i];
    return rev;
}

int main()
{


    int T;
    cin>>T;
    getchar();
    string str;
    string A;
    for(int i=1;i<=T;i++)
    {
        getline(cin,A);

        str=perfectstring(A);

        int len=str.length();
        if(perfectsquare(len)==false)
        {
            printf("Case #%d:\n",i);
            printf("No magic :(\n");
        }
        else
        {
            string C=stringreverse(str);
            int len1=C.length();

            int S=sqrt(len1);
            if(C==str)
                printf("Case #%d:\n%d\n",i,S);
            else
            {
                printf("Case #%d:\n",i);
                printf("No magic :(\n");
            }

        }


    }

    return 0;
}
