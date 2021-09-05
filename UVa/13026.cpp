#include <bits/stdc++.h>
using namespace std;

string mothernumber;

int uva13026(string number)
{
    int C;
    int len=mothernumber.length();
    C=0;
    for(int i=0;i<len;i++)
    {
        if(mothernumber[i]!=number[i])
            C++;
    }
    if(C==1 || C==0)
        return 1;
    else
        return 0;
}
int main()
{

    int T,N;
    cin>>T;
    string number[1000];

    for(int x=1;x<=T;x++)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>number[i];
        }
        cin>>mothernumber;
        printf("Case %d:\n",x);
        for(int i=0;i<N;i++)
        {
            if(uva13026(number[i]))
            {
                //print.push_back(number);
                cout<<number[i]<<endl;
            }

        }

    }
    return 0;
}
