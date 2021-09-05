#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL length(LL N)
{
    int C;
    C=0;
    while(N!=0)
    {
        int r=N%10;
        C++;
        N=N/10;
    }
    return C;
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    LL T;
    LL N;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>N;
        LL M;
        M=N;

        LL len=length(N);
        double sum=0;
        LL r;
        while(N!=0)
        {
            r=N%10;
            double power=pow(r,len);
            sum+= power;
            N=N/10;
        }

        if(M==sum)
        {
            cout<<"Armstrong"<<endl;
        }
        else
            cout<<"Not Armstrong"<<endl;
    }
    return 0;
}
