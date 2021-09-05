#include <bits/stdc++.h>
using namespace std;

int N,weight[1001],price[1001];

int dp[1000][1100];

int knapsack(int next,int current,int capacity)
{
    int profit1=0,profit2=0;

    if(next>N) return 0;

    else if(dp[next][current]!=-1) return dp[next][current];

    else if(current+weight[next] <= capacity)
    {
        profit1 = price[next] + knapsack(next+1, current+weight[next] , capacity);
    }

    profit2=knapsack(next+1 , current,capacity);

    dp[next][current]=max(profit1,profit2);

    return dp[next][current];
}

int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int T,G,capacity;

    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%d %d",&price[j],&weight[j]);
        }
        scanf("%d",&G);

        int sum=0;

        for(int j=1;j<=G;j++)
        {
            scanf("%d",&capacity);
            sum+=knapsack(0,0,capacity);
            memset(dp,-1,sizeof(dp));
        }

        printf("%d\n",sum);

        memset(weight,0,sizeof(weight));
        memset(price,0,sizeof(price));
    }
    return 0;

}
