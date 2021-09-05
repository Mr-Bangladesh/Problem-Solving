#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    while(cin>>s>>t)
    {
        string temp;
        int lens=s.length();
        int lent=t.length();
        for(int i=0;i<lens;i++)
        {
            for(int j=0;j<lent;j++)
            {
                if(s[i]==t[j])
                {
                    temp+=t[j];
                    t[j]='0';
                    break;
                }
                else
                    t[j]='0';
            }
        }
            if(temp==s)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
    }
    return 0;
}
