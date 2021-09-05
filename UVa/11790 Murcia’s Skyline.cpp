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

int main()
{
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        int a[n+1],w[n+1],l[n+1]={0},d[n+1]={0};
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int lis=0,lds=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&w[i]);
            d[i]=w[i];
            l[i]=w[i];
            lis=lds=max(lis,w[i]);
        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]>a[i]){
                    d[j]=max(d[j],d[i]+w[j]);
                    lis=max(lis,d[j]);
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]<a[i]){
                    l[j]=max(l[j],l[i]+w[j]);
                    lds=max(lds,l[j]);
                }
            }
        }
        if(lis>=lds){
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",cs++,lis,lds);
        }
        else{
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",cs++,lds,lis);
        }
    }

    return 0;
}


