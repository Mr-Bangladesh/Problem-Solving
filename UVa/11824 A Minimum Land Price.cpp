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
ll power(ll B,ll P){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=power(B,P/2);
        return R*R;
    }
    else{
        ll R=power(B,P-1);
        return R*B;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        vector<ll> v;
        ll n;
        while(scanf("%lld",&n)){
            if(n==0) break;
            v.pb(n);
            //cout<<n<<endl;
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ll lim=5000000;
        bool check=true;
        ll sum=0;
        for(int i=0;i<v.size();i++){
            ll x=power(v[i],i+1)*2;
            if(sum+x>lim){
                check=false; break;
            }
            sum+=x;
        }
        if(check) printf("%lld\n",sum);
        else printf("Too expensive\n");
    }

    return 0;
}

