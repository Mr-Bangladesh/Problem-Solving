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
int nod[1000005];
vector<int> v;
int main()
{
    for(int i=1;i<=1e6;i++){
        for(int j=i;j<=1e6;j+=i){
            nod[j]++;
        }
    }
    v.pb(1);
    int mx=0;
    for(int i=2;i<=64725;i++){
        int x=v.back();
        v.pb(x+nod[x]);
    }

    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int x,y;
        scanf("%d %d",&x,&y);
        int i=lower_bound(v.begin(),v.end(),x)-v.begin();
        int j=upper_bound(v.begin(),v.end(),y)-v.begin();
        printf("Case %d: %d\n",cs,j-i);
    }

    return 0;
}

