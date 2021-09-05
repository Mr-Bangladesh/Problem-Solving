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

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int m;
        scanf("%d",&m);
        ll a[m];
        for(int i=0;i<m;i++) scanf("%lld",&a[i]);
        //for(int i=0;i<m;i++) cout<<a[i]<<" "; cout<<endl;
        ll mx=-1; int res=0;
        for(int mask=(1<<m)-1;mask>=0;mask--){
            ll sum=0;
            for(int i=0;i<m;i++){
                if(mask&(1<<i)){
                    sum+=a[i];
                }
            }
            //cout<<sum<<" "<<mask<<endl;
            if(sum<=n && sum>mx){
                mx=sum;
                res=mask;
            }
        }
        //cout<<mx<<" "<<res<<endl;
        for(int i=0;i<m;i++){
            if(res&(1<<i)){
                printf("%lld ",a[i]);
            }
        }
        printf("sum:%lld\n",mx);
    }

    return 0;
}

