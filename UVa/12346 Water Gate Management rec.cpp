/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 1e15
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
int n,q;
ll f[20],c[20],v,t;
ll rec(int idx,ll sum){
    if(sum>=v) return 0;
    if(idx>n) return INF;
    ll x=c[idx]+rec(idx+1,sum+f[idx]*t);
    ll y=rec(idx+1,sum);
    return min(x,y);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&f[i],&c[i]);
    }
    scanf("%d",&q);
    for(int cs=1;cs<=q;cs++){
        scanf("%lld %lld",&v,&t);
        ll ans=rec(0,0);
        if(ans==INF){
            printf("Case %d: IMPOSSIBLE\n",cs);
        }
        else{
            printf("Case %d: %lld\n",cs,ans);
        }
    }

    return 0;
}

