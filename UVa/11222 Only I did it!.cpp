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
    int cs=1;
    while(t--){
        int n;
        set<int> prob;
        map<int, vector<int> > g;
        for(int i=1;i<=3;i++){
            scanf("%d",&n);
            for(int j=1;j<=n;j++){
                int x;
                scanf("%d",&x);
                prob.insert(x);
                g[x].pb(i);
            }
        }
        int fr[4]={0};
        map<int, vector<int> > li;
        for(auto it:prob){
            if(g[it].size()==1){
                fr[g[it][0]]++;
                li[g[it][0]].pb(it);
            }
        }
        int mx=0,id=1;
        for(int i=1;i<=3;i++){
            if(fr[i]>mx){
                mx=fr[i];
                id=i;
            }
        }
        printf("Case #%d:\n",cs++);
        printf("%d %d",id,li[id].size());
        for(int x:li[id]) printf(" %d",x);
        printf("\n");

    }

    return 0;
}

