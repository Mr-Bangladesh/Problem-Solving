/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int weight[102],value[102],dp[102][100005];

int cap,N;

int knapsack(int next,int current){
    int profit1=0,profit2=0;
    if(next>N) return 0;
    else if(dp[next][current]!=-1) return dp[next][current];
    else if(weight[next]+ current <=cap){
        profit1=value[next] + knapsack(next+1,weight[next]+current);
    }
    profit2=knapsack(next+1,current);
    dp[next][current]=max(profit1,profit2);
    return dp[next][current];
}


int main()
{
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        scanf("%d %d",&N,&cap);
        for(int i=0;i<=N;i++){
            for(int j=0;j<=cap;j++) dp[i][j]=-1;
        }
        for(int i=1;i<=N;i++){
            scanf("%d %d",&weight[i],&value[i]);
        }
        int res=knapsack(1,0);
        printf("Case %d: %d\n",cs++,res);


    }

    return 0;
}


