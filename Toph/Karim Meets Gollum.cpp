/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
#define EPS 1e-9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
//ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

vector<ll> Primes;
ll const MAX = 100000000;
bitset<MAX> prime;
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for(ll i = 2; i * i < MAX; ++i)
        if(prime[i])
            for(ll j = i * i; j < MAX; j += i)
                prime[j] = 0;
    for(ll i=2;i<=MAX;i++){
        if(prime[i]) Primes.pb(i);
    }
}

ll bigmod(ll B,ll P,ll M){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=bigmod(B,P/2,M);
        return ((R%M)*(R%M))%M;
    }
    else{
        ll R=bigmod(B,P-1,M);
        return ((R%M)*(B%M))%M;
    }
}

ll f(ll n,ll k){
    ll ans=1;
    for(int i=0;i<Primes.size() && Primes[i]*Primes[i]<=n;i++){
        if(n%Primes[i]) continue;
        ll x=1;
        ll cnt=0;
        while(n%Primes[i]==0){
            n/=Primes[i];
            cnt++;
            x+=bigmod(Primes[i],cnt*k,MOD);
        }
        ans=((ans%MOD)*(x%MOD))%MOD;
    }
    if(n!=1){
        ll x=(1+bigmod(n,k,MOD))%MOD;
        ans=((ans%MOD)*(x%MOD))%MOD;
    }
    return ans%MOD;
}


int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans=f(n,k);
        cout<<ans<<endl;
    }

    return 0;
}
