/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
///order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,x;
        scanf("%d %d",&n,&m);
        vector< pair<int,int> > v;
        vector<int> res;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(x>=m){
                res.pb(i);
            }
            else v.pb(mp(x,i));
        }
        sort(v.begin(),v.end(),cmp);
        for(auto it:v){
            res.pb(it.second);
        }
        for(int x:res) printf("%d ",x);
        printf("\n");
    }

    return 0;
}


