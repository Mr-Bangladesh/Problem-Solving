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
int n,k,a[22],b[22],dp[22][105];
int f(int idx,int amount){
    if(idx>n){
        if(amount==0) return 1;
        else return 0;
    }
    if(amount<0) return 0;
    if(dp[idx][amount]!=-1) return dp[idx][amount];
    int x=min(a[idx],b[idx]),y=max(a[idx],b[idx]);
    int ans=0;
    for(int i=x;i<=y;i++){
        ans+=f(idx+1,amount-i);
    }
    return dp[idx][amount]=ans;
}
int main()
{
    while(scanf("%d %d",&n,&k)){
        if(n==0 && k==0) break;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i],&b[i]);
        }
        memset(dp,-1,sizeof(dp));
        int ans=f(1,k);
        printf("%d\n",ans);
    }

    return 0;
}

