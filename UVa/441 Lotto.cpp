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
    int n;
    bool check=true;
    while(scanf("%d",&n),n){
        if(!check) printf("\n");
        check=false;
        int a[n+2];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n-5;i++){
            for(int j=i+1;j<=n-4;j++){
                for(int k=j+1;k<=n-3;k++){
                    for(int l=k+1;l<=n-2;l++){
                        for(int m=l+1;m<=n-1;m++){
                            for(int o=m+1;o<=n;o++){
                                printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[l],a[m],a[o]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

