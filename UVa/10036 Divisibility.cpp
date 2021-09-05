#include <bits/stdc++.h>
using namespace std;

int dp[10005][101];
int capacity;
int A[50000];
int N,K;

int knapsack(int pos,int amount)
{
    if(pos>=N)
    {
        if(amount==0) return 1;
        else return 0;
    }
    if(dp[pos][mod]!-1) return dp[pos][mod];

    int ret1=0,ret2=0;

    ret1=knapsack(i+1,(mod+A[pos])%K);

    ret2=knapsack(i+1,(mod-A[pos])%K);

    dp[pos][mod]=
}

int main()
{
    int T;
    cin>>T;

    for(int i=1;i<=T;i++)
    {
        cin>>N>>K;

        //int A[50000];
        for(int j=0;j<N;j++)
        {
            cin>>A[j];
        }

        for(int j=0;j<N;j++)
        {
            int P=knapsack();
            int Q=knapsack();
            if(P==1 || Q==1) cout<<"Divisible"<<endl;
            else cout<<"Not divisible"<<endl;
        }

    }
}
