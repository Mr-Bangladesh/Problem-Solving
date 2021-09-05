#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll make;
ll coin[]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
ll dp[22][10005];
ll coin_change(ll i,ll amount)
{
    if(amount==0) return 1;
    else if(i>=21)
    {
        if(amount==0) return 1;
        else return 0;
    }
    else if(dp[i][amount]!=-1) return dp[i][amount];

    ll ret1=0,ret2=0;
    if(amount-coin[i]>=0)
    {
        ret1=coin_change(i,amount-coin[i]);
    }
    ret2=coin_change(i+1,amount);

    dp[i][amount]=ret1+ret2;
    return dp[i][amount];

}


int main()
{
    ll result[10005]={0};
    result[0]=1;
    memset(dp,-1,sizeof(dp));
    for(make=1;make<=10005;make++)
    {
        coin_change(0,make);
        result[make]=dp[0][make];
    }

    ll N;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    while(cin>>N)
    {

        ll ans=result[N];
        cout<<ans<<endl;
    }
    return 0;
}
