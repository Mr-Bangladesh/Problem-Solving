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

ll dp[1000003],a[20],M;
ll f(ll n){
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=M;j++){
            if(i-a[j]>=0){
                if(dp[i-a[j]]==0){
                    dp[i]=1;
                }
            }
        }
    }
    return dp[n];
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=m;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        M=m;
        int x=f(n);
        if(x){
            printf("Stan wins\n");
        }
        else{
            printf("Ollie wins\n");
        }
    }

    return 0;
}


