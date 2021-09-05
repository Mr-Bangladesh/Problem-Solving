#include <bits/stdc++.h>
using namespace std;



int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int T;
    string input;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>input;

        //cout<<score(input)<<endl;

        int len=input.length();
        int sum=0;
        int C=0;
        for(int i=0;i<len;i++)
        {
            if(input[i]=='X')
            {
                C=0;
            }
            else
            {
                C++;
                sum+=C;
            }

    }
        cout<<sum<<endl;

    }
    return 0;
}
