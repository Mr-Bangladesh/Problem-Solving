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
ll dp[50];
void pre(){
    dp[0]=0; dp[1]=1;
    for(int i=2;i<=40;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
}
int main()
{
    pre();
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll m=n;
        string ans="";
        int last=-1;
        while(n!=0){
            int i=upper_bound(dp,dp+41,n)-dp; i--;
            //cout<<n<<" "<<i<<" "<<dp[i]<<" "<<last<<endl;
            //ans+='1';
            for(int j=last;j>i+1;j--) ans+='0';
            ans+='1';
            last=i;
            n-=dp[i];
        }
        //cout<<last<<endl;
        for(int i=last;i>2;i--) ans+='0';
        printf("%lld = ",m);
        cout<<ans;
        printf(" (fib)\n");
    }

    return 0;
}


