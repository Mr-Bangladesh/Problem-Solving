#include <bits/stdc++.h>
using namespace std;
int make;
int coin[]={50,25,10,5,1};
int dp[6][8000];

int coin_change(int i,int amount)
{
    if(amount==make) return 1;
    else if(i>=5)
    {
        if(amount==make) return 1;
        else return 0;
    }
    else if(dp[i][amount]!=-1) return dp[i][amount];
    int ret1=0,ret2=0;
    if(amount+coin[i]<=make)
    {
        ret1=coin_change(i,amount+coin[i]);
    }
    ret2=coin_change(i+1,amount);

    dp[i][amount]=ret1+ret2;
    return dp[i][amount];
}
int main()
{
    int result[8000]={0};

    for(make=1;make<=7489;make++)
    {
        memset(dp,-1,sizeof(dp));
        coin_change(0,0);
        result[make]=dp[0][0];
    }
    int N;
    while(cin>>N)
    {
        //memset(dp,-1,sizeof(dp));
        //coin_change(0,0);
        cout<<result[N]<<endl;
    }
}
