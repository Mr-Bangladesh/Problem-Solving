#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    int len;
    long long sum;
    int r;
    int i;
    while(cin>>n)
    {
        //B=n;
        if(n=="0")
            break;
        len=n.length();
        list <int> binary;
        list <int>:: iterator it;
        for(i=0;i<len;i++)
        {
            binary.push_front(n[i]-'0');
        }

        i=1;
        sum=0;
        for(it=binary.begin();it!=binary.end();it++)
            {
                sum=sum+(*it)*(pow(2,i)-1);
                i++;
            }
        cout<<sum<<endl;
    }
    return 0;
}
