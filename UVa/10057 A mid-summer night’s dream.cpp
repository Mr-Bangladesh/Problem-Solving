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
        int a[n+2];
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans1,ans2,ans3;
        ans1=a[(n+1)/2];
        ans2=upper_bound(a+1,a+n+1,ans1)-lower_bound(a+1,a+n+1,ans1);
        if(n%2) ans3=1;
        else{
            int x=a[n/2],y=a[n/2+1];
            if(x==y) ans3=1;
            else ans3=y-x+1;
            if(ans3>1){
                ans2+=(upper_bound(a+1,a+n+1,y)-lower_bound(a+1,a+n+1,y));
            }
        }
        printf("%d %d %d\n",ans1,ans2,ans3);
    }
    return 0;
}

