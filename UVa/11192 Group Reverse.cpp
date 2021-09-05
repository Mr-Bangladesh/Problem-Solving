#include <bits/stdc++.h>
using namespace std;
int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int N;
    string S;
    while(cin>>N)
    {
        if(N==0) break;

        cin>>S;

        int len=S.length();
        N=len/N;
        string A;

        for(int i=0;i<len;i+=N)
        {
            for(int j=i+N-1;j>=i;j--)
            {
                A+=S[j];
            }
        }

        cout<<A<<endl;
    }
    return 0;
}
