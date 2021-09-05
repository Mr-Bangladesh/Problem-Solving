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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
int dp[22][1005],a[22];
int f(int i,int sum){
    //cout<<i<<" "<<sum<<endl;
    if(sum<0) return 0;
    if(sum==0) return 1;
    if(i==0) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int x=f(i-1,sum-a[i]);
    int y=f(i-1,sum);
    return dp[i][sum]=x|y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&m,&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,-1,sizeof(dp));
        int ans=f(n,m);
        if(ans) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

