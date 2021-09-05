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

string tolower(string A)
{
    string B;
    int len=A.length();
    for(int i=0;i<len;i++)
    {
        if(A[i]>=65 && A[i]<=90)
            B+=(A[i]+32);
        else
            B+=A[i];
    }
    return B;
}

int main()
{
    while(1)
    {
        string A,B;


        getline(cin,A);
        if(A=="DONE")
            break;

        int len=A.length();

        for(int i=0;i<len;i++)
        {
            if(A[i]!='.' && A[i]!=',' && A[i]!='?' && A[i]!='!' && A[i]!=32)
                B+=A[i];
        }
        string C=stringreverse(B);
        C=tolower(C);
        B=tolower(B);

        //cout<<B<<endl<<C<<endl;

        if(B==C)
            cout<<"You won't be eaten!"<<endl;
        else
            cout<<"Uh oh.."<<endl;
    }
    return 0;
}
