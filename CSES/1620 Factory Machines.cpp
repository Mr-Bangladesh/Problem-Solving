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
ll a[maxn];
ll n,m;
bool can(ll mid){
    ll cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=min(mid/a[i],1e9);
    }
    //cout<<mid<<" "<<cnt<<" "<<m<<endl;
    if(cnt>=m) return true;
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=1,r=1e18;
    while(l<=r){
        ll mid=(l+r)/2;
        if(can(mid)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<endl;

    return 0;
}


