/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll max(ll a,ll b,ll c){return max(a,max(b,c));} ll min(ll a,ll b,ll c){return min(a,min(b,c));}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    int t,n,m,x,y,w,k,q,r,p,cs;

    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int a[n+2][m+2],dp[n+2][m+2];
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=a[i][j]+max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            ans=max(ans,dp[n][i]);
        }
        printf("%d\n",ans);
    }

    return 0;
}


