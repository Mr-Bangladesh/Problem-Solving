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

int M,C,price[30][30];

int DP[206][30];

int shop(int money,int g)
{
    if(money<0) return -1;

    if(g==C) return M-money;

    if(DP[money][g]!=-1) return DP[money][g];

    int ans=-1;

    for(int i=1;i<=price[g][0];i++)
    {
        ans=max(ans,shop(money-price[g][i],g+1));
    }
    return DP[money][g]=ans;

}

int main()
{
    //freopen("1.txt","r",stdin);

    int TC;

    cin>>TC;

    while(TC--)
    {
        cin>>M>>C;

        for(int i=0;i<C;i++)
        {
            cin>>price[i][0];

            for(int j=1;j<=price[i][0];j++) cin>>price[i][j];
        }

        memset(DP,-1,sizeof(DP));

        int ans=shop(M,0);

        if(ans==-1) printf("no solution\n");
        else printf("%d\n",ans);

        memset(price,0,sizeof(price));
    }

    return 0;
}
