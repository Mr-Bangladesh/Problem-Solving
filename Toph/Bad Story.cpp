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
ll nod[1000005],ans[1000005];
int main()
{
    for(int i=1;i<=1000000;i++){
        nod[i]=1;
    }
    for(int i=2;i<=1000000;i++){
        for(int j=i;j<=1000000;j+=i){
            nod[j]++;
        }
    }

    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;i++){
        ans[nod[a[i]]]+=a[i];
    }
    for(int i=1;i<=1000000;i++){
        ans[i]+=ans[i-1];
        //cout<<i<<" "<<a[i]<<endl;
    }
    //cout<<"OK"<<endl;
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%lld\n",ans[x]);
    }


    return 0;
}


