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

ll sum[1002][1002];
ll dp[1002][1002];
ll n,m,k,l;
ll f(int i,int j){
    //cout<<"par "<<i<<" "<<j<<endl;
    if(i>n || j<k) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    //ll cur=sum[i][j+k-1]-sum[i][j-1];
    ll cur=sum[i][j]-sum[i][j-k];
    //if(i==1 && j-k+1==5)
    ///cout<<i<<" "<<j-k+1<<" "<<i<<" "<<j<<" "<<cur<<endl;
    ll ss=0;
    for(int s=j;s>=j-k+1;s--){
        for(int x=k;x<=m;x++){
            if(abs(s-x)<=l){
                //cout<<i<<" "<<j<<" "<<i+1<<" "<<x<<endl;
                //cout<<"child "<<
                ss=max(ss,f(i+1,x));
            }
        }
    }
    //cout<<i<<" "<<j<<" "<<ss+cur<<endl;
    return dp[i][j]=ss+cur;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld %lld",&n,&m,&k,&l);
        ll a[n+1][m+1];
        memset(sum,0,sizeof(sum));
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%lld",&a[i][j]);
                sum[i][j]=sum[i][j-1]+a[i][j];
            }
        }
        ll ans=0;
        for(int j=m;j>=k;j--){
            ans=max(ans,f(1,j));
        }
        //ll ans=f(0,m);
        printf("%lld\n",ans);
    }

    return 0;
}


