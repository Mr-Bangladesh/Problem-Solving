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
ll a[100005];
int main()
{
    ll n,m;
    cin>>n>>m;
    if(n==0 && m==0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    vector<ll> v;
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++){
        if(a[i]!=a[i-1]){
            v.pb(a[i]-a[i-1]);
        }
    }
    //cout<<"ok"<<endl;
    if(a[m]!=n){
        v.pb(n-a[m]);
    }
    //cout<<"ok"<<endl;
    ll g=v[0];
    for(ll x:v){
        g=__gcd(g,x);
    }
    //cout<<g<<endl;
    cout<<((n/g)-1)<<endl;

    return 0;
}


