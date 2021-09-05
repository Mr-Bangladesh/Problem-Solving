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

bool sq(ll n){
    ll x=sqrt(n);
    return x*x==n;
}
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
    for(int i=2;i<=MAX;i++){
        if(prime[i]) Primes.pb(i);
    }
}
ll nod(ll n){
    ll cnt=1;
    for(int i=0;Primes[i]*Primes[i]<=n;i++){
        if(n%Primes[i]) continue;
        ll x=0;
        while(n%Primes[i]==0){
            x++;
            n/=Primes[i];
        }
        cnt*=(x+1);
    }
    if(n!=1){
        cnt*=2;
    }
    return cnt;
}
int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        n*=2;
        ll cnt=(ll)sq(n);
        cnt+=(nod(n)/2);
        cout<<cnt<<endl;
    }

    return 0;
}


