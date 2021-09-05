#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,f,area,animal,degree,j,i,sum;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>f;
        sum=0;
        for(j=1;j<=f;j++)
        {
            cin>>area>>animal>>degree;
            sum=sum+(area*degree);
        }
        cout<<sum<<endl;
    }
    return 0;
}
