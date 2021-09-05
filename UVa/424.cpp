#include <bits/stdc++.h>
using namespace std;

string stringreverse(string S);
string stringadd(string a,string b);

int main()
{
    string A;
    string sum="0";
    while(cin>>A)
    {
        if(A=="0")
        {
            cout<<sum<<endl;
            break;
        }
        sum=stringadd(sum,A);
    }
    return 0;
}

string stringreverse(string S)
{
    string rev;
    int len=S.length();
    for(int i=len-1;i>=0;i--)
        rev+=S[i];
    return rev;
}


string stringadd(string a,string b)
{
    int len1=a.length();
    int len2=b.length();
    a=stringreverse(a);
    b=stringreverse(b);
    string one;
    string two;
    if(len1==len2)
    {
        one=a;
        two=b;
    }
    else if(len1>len2)
    {
        for(int i=len2;i<len1;i++)
            b+="0";
        one=a;
        two=b;
    }
    else if(len1<len2)
    {
        for(int i=len1;i<len2;i++)
            a+="0";
        one=a;
        two=b;
    }

    int len=one.length();

    int S,rem,carry;
    string summation;
    carry=0;
    for(int i=0;i<len;i++)
    {
        S=(one[i] - 48) + (two[i] - 48) + carry;
        rem=S%10;
        summation+=(rem + 48);
        if(S<10)
            carry=0;
        else if(S>=10)
            carry=1;
    }
    if(carry==1)
        summation+="1";

    return stringreverse(summation);
}
