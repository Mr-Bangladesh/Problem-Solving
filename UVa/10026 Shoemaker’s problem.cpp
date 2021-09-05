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

struct ff{
    int time,fine,idx;
    ff(int a,int b,int c){
        time=a; fine=b; idx=c;
    }
};
bool comp(ff a,ff b){
    int x=a.time*b.fine;
    int y=a.fine*b.time;
    if(x==y) return a.idx<b.idx;
    return x<y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x,y;
        scanf("%d",&n);
        vector<ff> v;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&x,&y);
            v.pb(ff(x,y,i));
        }
        sort(v.begin(),v.end(),comp);
        printf("%d",v[0].idx);
        for(int i=1;i<n;i++){
            printf(" %d",v[i].idx);
        }
        printf("\n");
        if(t) printf("\n");
    }

    return 0;
}

