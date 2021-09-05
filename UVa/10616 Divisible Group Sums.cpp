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

ll mod(ll B,ll M)
{
    ll X=B%M;
    if(X>=0) return X;
    else return M+X;
}

ll A[20000],N,Q,D,M,A1[20000];

ll DP[405][205][25];

ll knapsack(ll S,ll i,ll C)
{
    //cout<<S<<" "<<i<<" "<<C<<endl;

    if(C>M) return 0;

    if(C==M && mod(S,D)==0) return 1;
    if(C==M && mod(S,D)!=0) return 0;
    if(i>N)
    {
        if(C==M && mod(S,D)==0) return 1;
        else return 0;
    }

    if(DP[S][i][C]!=-1) return DP[S][i][C];

    ll R1=0,R2=0;

    //R1=knapsack(mod(S+A[i],D),i+1,C+1);
    R1=knapsack(S+A1[i],i+1,C+1);

    //R2=knapsack(mod(S,D),i+1,C);
    R2=knapsack(S,i+1,C);

    //cout<<S<<" "<<i<<" "<<C<<" "<<R1<<" "<<R2<<endl;

    return DP[S][i][C]=R1+R2;
    //return R1+R2;

}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    ll TC=1;
    while(scanf("%lld %lld",&N,&Q))
    {
        if(N==0 && Q==0) break;

        for(ll i=1;i<=N;i++) scanf("%lld",&A[i]);

        printf("SET %lld:\n",TC);

        for(ll i=1;i<=Q;i++)
        {
            scanf("%lld %lld",&D,&M);

            for(int j=1;j<=N;j++)
            {
                A1[j]=mod(A[j],D);
            }

            memset(DP,-1,sizeof(DP));

            ll ans=knapsack(0,1,0);

            printf("QUERY %lld: %lld\n",i,ans);

        }
        TC++;
    }

    return 0;
}
