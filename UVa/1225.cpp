#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    ULL T,N,rem,b;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>N;
        ULL A[10]={0,0,0,0,0,0,0,0,0,0};
        for(int i=1;i<=N;i++)
        {
            b=i;
            while(b!=0)
            {
                rem=b%10;
                A[rem]++;
                b=b/10;
            }
        }
        int m=1;
        for(int k=0;k<10;k++)
        {
            cout<<A[k];
            if(m<10)
                cout<<" ";
            m++;
        }
        cout<<endl;
    }
    return 0;
}
