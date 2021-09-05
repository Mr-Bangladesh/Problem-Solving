#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll make;
ll coin[]={1,5,10,25,50};
ll dp[6][30005];
ll coin_change(ll i,ll amount)
{
    if(amount==0) return 1;
    else if(i>=5)
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
    for(make=1;make<=30001;make++)
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
        //cout<<"N"<<N<<endl;
        if(ans==1) printf("There is only %lld way to produce %lld cents change.\n",ans,N);
        else printf("There are %lld ways to produce %lld cents change.\n",ans,N);
    }
    return 0;
}
