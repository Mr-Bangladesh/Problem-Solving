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

int main()
{
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        ll n,m;
        scanf("%lld %lld",&n,&m);
        if(n==m){
            printf("Case %d: 0\n",cs);
            continue;
        }
        n-=m;
        ll x=sqrt(n);
        //cout<<n<<" "<<m<<" "<<x<<endl;
        vector<ll> v;
        for(ll i=1;i<=x;i++){
            if(n%i) continue;
            ll j=n/i; //cout<<i<<" "<<j<<endl;
            if(i==j){
                if(i>m) v.pb(i);
            }
            else{
                if(i>m) v.pb(i);
                if(j>m) v.pb(j);
            }
        }
        sort(v.begin(),v.end());
        if(!v.size()){
            printf("Case %d:\n",cs);
        }
        else{
            printf("Case %d:",cs);
            for(ll x:v) printf(" %lld",x);
            printf("\n");
        }
    }

    return 0;
}
