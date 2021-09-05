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
    int n,m;
    while(scanf("%d %d",&n,&m),n||m){
        int a[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int q,x,y;
        scanf("%d",&q);
        while(q--){
            scanf("%d %d",&x,&y);
            int mx=0;
            for(int r=1;r<=n;r++){
                int c=lower_bound(a[r]+1,a[r]+m+1,x)-a[r];
                if(c==m+1) continue;
                for(int i=mx;i<=n;i++){
                    int r1=r+i; int c1=c+i;
                    if(r1>n || c1>m) break;

                    if(a[r1][c1]>y) break;
                    mx=max(mx,i+1);
                }
            }
            printf("%d\n",mx);
        }
        printf("-\n");
    }

    return 0;
}

