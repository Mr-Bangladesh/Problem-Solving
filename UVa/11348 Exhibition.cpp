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
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        vector<int> lisst[10005];
        for(int i=1;i<=n;i++){
            int m,x;
            scanf("%d",&m);
            for(int j=1;j<=m;j++){
                scanf("%d",&x);
                lisst[x].pb(i);
            }
        }
        int total=0;
        int cnt[n+2]={0};
        for(int i=0;i<=10000;i++){
            if(lisst[i].size()==1){
                cnt[lisst[i][0]]++;
                total++;
            }
        }
        printf("Case %d:",cs);
        for(int i=1;i<=n;i++){
            double per=(double)cnt[i]/(double)total;
            printf(" %.6f%c",per*100.00,37);
        }
        printf("\n");
    }

    return 0;
}

