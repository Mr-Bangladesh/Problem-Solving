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

int main()
{
    ll t;
    cin>>t;
    ll n,m;
    while(t--){
        cin>>n>>m;
        vector<ll> v;
        ll x;
        for(int i=1;i<=m;i++){
            cin>>x;
            v.pb(x);
        }
        ll sum=0;
        sort(v.rbegin(),v.rend());
        for(int i=0;i<min(n,m);i++){
            sum+=v[i];
        }
        cout<<sum<<endl;
    }

    return 0;
}


