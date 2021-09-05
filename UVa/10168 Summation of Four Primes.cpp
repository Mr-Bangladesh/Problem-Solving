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
vector<ll> Primes;
ll const MAX = 10000000;
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
int main()
{
    sieve();

        //freopen("1.txt","r",stdin);

    ll n;
    while(scanf("%lld",&n)!=EOF){
        if(n<8){
            cout<<"Impossible."<<endl;
            continue;
        }
        if(n%2==0){
            cout<<2<<" "<<2<<" ";
            n-=4;
        }
        else{
            cout<<2<<" "<<3<<" ";
            n-=5;
        }
        for(ll x:Primes){
            if(prime[n-x]){
                //printf("2 2 %lld %lld\n",x,n-x);
                cout<<x<<" "<<n-x<<endl;
                break;
            }
        }
    }

    return 0;
}

