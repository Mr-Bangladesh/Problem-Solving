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

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    int dp[n+1]={0};

    for(int j=1;j<k;j++){

        int tmp[n+1]={0};
        set<int> s;

        for(int i=n;i>=1;i--){
            if(dp[i]==INT_MAX){
                tmp[i]=INT_MAX;
                continue;
            }
            s.insert(a[i]+dp[i]);
            auto it=s.upper_bound(a[i]+dp[i]);
            //cout<<a[i]<<" "<<dp[i]<<" "<<*it<<endl;
            if(it==s.end()){
                tmp[i]=INT_MAX;
                continue;
            }
            tmp[i]=*it-a[i];
        }
        for(int i=1;i<=n;i++){
            dp[i]=tmp[i];
        }
        //for(int i=1;i<=n;i++) cout<<dp[i]<<" "; cout<<endl;
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++) ans=min(ans,dp[i]);
    if(ans==INT_MAX) ans=-1;
    printf("%d\n",ans);

    return 0;
}

