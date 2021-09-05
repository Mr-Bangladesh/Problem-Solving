#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll make;
ll coin[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[12][30005];
ll coin_change(ll i,ll amount)
{
    if(amount==0) return 1;
    else if(i>=11)
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
    ll result[30005]={0};
    result[0]=1;
    memset(dp,-1,sizeof(dp));
    for(make=1;make<=30005;make++)
    {
        coin_change(0,make);
        result[make]=dp[0][make];
    }

    float N;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    //cout<<result[3885]<<endl;
    while(cin>>N)
    {
        if(N==0.00) break;
        N=N+0.001;

        float N2=N*100.00;
        ll N1=N2;
        //cout<<N1<<" "<<N2<<endl;
        ll ans=result[N1];
        printf("%6.2f%17lld\n",N,ans);
    }
    return 0;
}
