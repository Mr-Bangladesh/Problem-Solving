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
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
        vector< pair<int,int> > v1,v2;
        int a[n+1],b[n+1];
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i],&b[i]);
            v1.pb({a[i],b[i]});
            v2.pb({b[i],a[i]});
        }
        sort(v1.begin(),v1.end(),cmp);
        sort(v2.begin(),v2.end(),cmp);
        bool check=true;
        for(int i=0;i<n;i++){
            if(v1[i]!=v2[i]){
                check=false; break;
            }
        }
        if(check) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

