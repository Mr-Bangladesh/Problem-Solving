#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll pow(ll B,ll P) { ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;}
int fx4[]={1,-1,0,0}; int fy4[]={0,0,1,-1};

int V[1000],F[2000],N,M,Count=0; ///N=total budget, M=items
int DP[10004][105];

int knapsack(int amount,int i,int Cap)
{
    if(i>M) return 0;

    if(DP[amount][i]!=-1) return DP[amount][i];

    int R1=0,R2=0;

    if(amount+V[i]<=Cap)
        R1=F[i]+knapsack(amount+V[i],i+1,Cap);

    R2=knapsack(amount,i+1,Cap);

    //cout<<R1<<" "<<R2<<endl;

    return DP[amount][i]=max(R1,R2);
}

int main()
{
    freopen("1.txt","r",stdin);

    while(scanf("%d %d",&N,&M)!=EOF)
    {
        for(int i=1;i<=M;i++)
        {
            cin>>V[i]>>F[i];
        }

        if(N>=2000) N+=200;

        memset(DP,-1,sizeof(DP));

        int ans=knapsack(0,1,N);

        printf("%d\n",ans);
    }

    return 0;
}
