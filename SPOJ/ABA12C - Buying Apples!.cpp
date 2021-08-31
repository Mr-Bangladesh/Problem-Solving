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
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
int a[104],dp[105][105][105];
int N,K;
int f(int i,int j,int w){
    //cout<<i<<" "<<j<<" "<<w<<endl;
    if(w==0) return 0;
    if(i>K || j>N || w<0) return 100000;
    if(dp[i][j][w]!=-1) return dp[i][j][w];
    int r1,r2,r3;
    r1=r2=r3=100000;
    if(a[i]!=-1){
        r1=a[i]+f(i,j+1,w-i);
        r2=f(i+1,j,w);
    }
    else{
        r3=f(i+1,j,w);
    }
    return dp[i][j][w]=min(r1,min(r2,r3));
}
int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    int t,n,m,x,y,w,k,q,r,p,cs;

    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        N=n;K=k;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]);
        }
        int ans=f(1,0,k);
        if(ans==100000) ans=-1;
        printf("%d\n",ans);
    }

    return 0;
}


