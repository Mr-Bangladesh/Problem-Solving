#include <bits/stdc++.h>
using namespace std;
int channel(int a,int b)
{
    int i,sum,m,n;
    m=abs(b-a);
    n=abs(100-a+b);
    if(m<=n)
    {
        return m;}
    else {
        return n;}
}
int main()
{
    int a,b,sum;
    //freopen("file2.txt","w",stdout);
    while(cin>>a>>b)
    {
        if(a==-1 && b==-1)
            break;
        else if(a<=b)
            cout<<channel(b,a)<<endl;
    else if(a>b)
        cout<<channel(a,b)<<endl;
    }
    return 0;
}
