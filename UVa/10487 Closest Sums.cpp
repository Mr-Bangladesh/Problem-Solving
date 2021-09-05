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
    //freopen("1.txt","r",stdin);
    int n,cs=1;
    while(scanf("%d",&n),n){
        printf("Case %d:\n",cs++);
        int a[n+2];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        vector<int> v;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                v.pb(a[i]+a[j]);
            }
        }
        sort(v.begin(),v.end());
        int q;
        scanf("%d",&q);
        while(q--){
            int x;
            scanf("%d",&x);
            printf("Closest sum to %d is ",x);
            int idx=upper_bound(v.begin(),v.end(),x)-v.begin();
            if(idx==v.size()){
                printf("%d.\n",v[idx-1]);
            }
            else if(idx==0) printf("%d.\n",v[idx]);
            else{
                int l=v[idx]-x; int r=x-v[idx-1];
                if(l<r){
                    printf("%d.\n",v[idx]);
                }
                else{
                    printf("%d.\n",v[idx-1]);
                }
            }
        }
    }

    return 0;
}

