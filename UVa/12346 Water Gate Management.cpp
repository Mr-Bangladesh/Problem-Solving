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
    int n,q;
    scanf("%d",&n);
    ll f[n],c[n],v,t;
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&f[i],&c[i]);
    }
    scanf("%d",&q);
    for(int cs=1;cs<=q;cs++){
        scanf("%lld %lld",&v,&t);
        ll ans=INF;
        for(int mask=0;mask<(1<<n);mask++){
            ll sum=0,cost=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    sum+=(f[i]*t);
                    cost+=c[i];
                    if(sum>=v) break;
                }
            }
            if(sum>=v){
                ans=min(ans,cost);
            }
        }
        if(ans==INF){
            printf("Case %d: IMPOSSIBLE\n",cs);
        }
        else{
            printf("Case %d: %lld\n",cs,ans);
        }
    }

    return 0;
}

