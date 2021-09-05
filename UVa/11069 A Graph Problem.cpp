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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

ll dp[100];
ll f(int n){
    //cout<<n<<endl;
    if(n<1) return 0;
    if(n==1 || n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    int cnt=f(n-2)+f(n-3);
    return dp[n]=cnt;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ll res[100];
    res[0]=0;
    for(int i=1;i<=76;i++){
        res[i]=f(i);
    }

    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",res[n]+res[n-1]);
    }

    return 0;
}


