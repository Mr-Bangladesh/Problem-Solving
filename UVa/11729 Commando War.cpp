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
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second>b.second;
}
int main()
{
    int n,cs=1;
    while(scanf("%d",&n),n){
        vector< pair<int,int> > v;
        int x,y;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&x,&y);
            v.pb({x,y});
        }
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        x=0; y=0;
        for(auto it:v){
            x+=it.first;
            y=x+it.second;
            ans=max(ans,y);
        }
        printf("Case %d: %d\n",cs++,ans);
    }

    return 0;
}

