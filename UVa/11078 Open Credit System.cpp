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
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[n+2];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int mx[n+2],mn[n+2];
        mx[1]=a[1];mn[n]=a[n];
        for(int i=2;i<=n;i++){
            mx[i]=max(mx[i-1],a[i]);
        }
        for(int i=n-1;i>=1;i--){
            mn[i]=min(mn[i+1],a[i]);
        }

        int ans=-1;
        for(int i=1;i<n;i++){
            if(mx[i]>=mn[i+1]){
                ans=max(ans,mx[i]-mn[i+1]);
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

