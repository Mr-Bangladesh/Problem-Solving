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
int n,m,p[102],b[102],l[102],r[102];

int dp[102][1002];

int f(int cur,int sum){
    if(cur>n) return 0;
    if(sum>m) return 0;
    if(dp[cur][sum]!=-1) return dp[cur][sum];
    int ans=0;
    for(int i=0;i<=r[cur];i++){
        if(sum+p[cur]*i<=m){
            int x=b[cur]*i+f(cur+1,sum+p[cur]*i);
            ans=max(ans,x);
        }
    }
    return dp[cur][sum]=ans;
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>l[i];
    for(int i=1;i<=n;i++) cin>>r[i];

    ll mn=0,sum=0;

    for(int i=1;i<=n;i++){
        mn+=(l[i]*p[i]);
        sum+=(l[i]*b[i]);
    }

    if(mn>m){
        cout<<0<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++) r[i]-=l[i];

    m-=mn;

    memset(dp,-1,sizeof(dp));

    int ans=f(1,0);
    ans+=sum;

    cout<<ans<<endl;

    return 0;
}


