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
int n,m,a[1002];
bool check(int x){
    int sum=0,cnt=1;
    for(int i=1;i<=n;i++){
        if(sum+a[i]<=x){
            sum+=a[i];
        }
        else{
            sum=a[i];
            cnt++;
        }
    }
    return cnt<=m;
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF){
        int l=0,r=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            l=max(l,a[i]);
            r+=a[i];
        }
        int ans=-1;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid)){
                r=mid;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        printf("%d\n",l);
    }

    return 0;
}

