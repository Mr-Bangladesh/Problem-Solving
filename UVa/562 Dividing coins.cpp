           ///Faizul///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define push_back pb
#define make_pair mp
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

int dp[1000][50005];
int capacity,value[10000],weight[10000];
int coins;

int knapsack(int pos,int amount)
{
    //if(pos>=coins) return 0;
    if(pos>=coins || amount>capacity) return 0;

    else if(dp[pos][amount]!=-1) return dp[pos][amount];

    int ret1=0,ret2=0;
    //cout<<"amount "<<amount<<endl;

    if(amount+weight[pos]<=capacity)
        ret1=value[pos]+knapsack(pos+1,amount+weight[pos]);

    ret2=knapsack(pos+1,amount);

    dp[pos][amount]=max(ret1,ret2);

    return dp[pos][amount];

}
int main()
{
    FastIO();

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int test;
    cin>>test;
    for(int k=1;k<=test;k++)
    {
        memset(dp,-1,sizeof(dp));

        cin>>coins;

        int sum=0;

        for(int i=0;i<coins;i++)
        {
            cin>>value[i];

            sum+=value[i];

            weight[i]=value[i];
        }


        //sort(value,value+coins);
        //sort(weight,weight+coins);

//        for(int i=0;i<coins;i++)
//        {
//            cout<<"value "<<value[i]<<" weight "<<weight[i]<<endl;
//        }




        capacity=sum/2;
        //cout<<"Cap "<<capacity<<"sum "<<sum<<endl;

        int ans=knapsack(0,0);
        //cout<<"ans "<<ans<<" "<<dp[0][0]<<endl;
        //cout<<"fdf "<<ans<<endl;
        ans=ans*2;

        ans=abs(sum-ans);
        cout<<ans<<endl;

        memset(value,0,sizeof(value));
        memset(weight,0,sizeof(weight));
        capacity=0;
        coins=0;

    }
}
