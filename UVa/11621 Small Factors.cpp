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
vector<ll> v;
ll p2[40],p3[40];
int main()
{
    p2[0]=p3[0]=1;
    ll s=1;
    for(int i=1;i<=32;i++){
        s=s*2;
        p2[i]=s;
        //cout<<i<<" "<<s<<endl;
    }
    s=1;
    for(int i=1;i<=20;i++){
        s=s*3;
        p3[i]=s;
        //cout<<i<<" "<<s<<endl;
    }

    for(int i=0;i<=31;i++){
        for(int j=0;j<=20;j++){
            ll x=p2[i]*p3[j];
            if(x<=(1LL<<32)){
                v.pb(x);
            }
        }
    }

    sort(v.begin(),v.end());

    ll n;
    while(scanf("%lld",&n),n){
        ll i=lower_bound(v.begin(),v.end(),n)-v.begin();
        printf("%lld\n",v[i]);
    }

    return 0;
}

