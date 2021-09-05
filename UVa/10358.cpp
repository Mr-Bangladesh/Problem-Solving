#include <bits/stdc++.h>
using namespace std;
#define MIN 100000
int solve(int HH,int MM,int H,int M)
{
    if(H>HH)
    {
        //cout<<H<<endl<<HH<<endl;
        HH=12-HH + H;
    }
    int result=(HH*60 + MM)-(H*60 + M);
    return result;
}

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    int T,K,HH,Q,MM,H,M,S,minimum;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>K;
        scanf("%d:%d",&H,&M);
        minimum=MIN;
        for(int j=1;j<=K;j++)
        {
            scanf("%d:%d",&HH,&MM);
            cin>>Q;
            S=solve(HH,MM,H,M) + Q;
            if(S<minimum)
                minimum=S;
        }
        printf("Case %d: %d\n",i,minimum);
    }
    return 0;
}
