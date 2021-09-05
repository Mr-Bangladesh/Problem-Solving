#include <bits/stdc++.h>
using namespace std;
int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int T;
    string n;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        cin>>n;

        int len=n.length();

        char last_digit=n[len-1];

        if(n=="0")
        {
            cout<<"1"<<endl;
            continue;
        }
        else if(n=="1")
        {
            cout<<"66"<<endl;
        }
        else if(last_digit=='1' && n[len-2]=='0')
        {
            cout<<"16"<<endl;
        }
        else if(last_digit=='1')
            cout<<"16"<<endl;

        else if(last_digit=='2' || last_digit=='7')
            cout<<"56"<<endl;

        else if(last_digit=='3' || last_digit=='8')
            cout<<"96"<<endl;

        else if(last_digit=='4' || last_digit=='9')
            cout<<"36"<<endl;

        else if(last_digit=='5' || last_digit=='0')
            cout<<"76"<<endl;

        else if(last_digit=='6')
            cout<<"16"<<endl;
    }
    return 0;

}
