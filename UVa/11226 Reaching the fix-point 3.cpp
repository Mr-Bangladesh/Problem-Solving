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
vector<ll> Primes;
ll const MAX = 500000;
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
int sopf(int n){
    int s=0;
    for(int i=0;Primes[i]*Primes[i]<=n;i++){
        if(n%Primes[i]) continue;
        while(n%Primes[i]==0){
            s+=Primes[i];
            n/=Primes[i];
        }
    }
    if(n!=1) s+=n;
    return s;
}
int dp[500004];
int main()
{
    sieve();
    dp[1]=1;
    int n=500000;
    for(int i=2;i<=n;i++){
        int x=sopf(i);
        if(x==i){
            dp[i]=1;
        }
        else{
            dp[i]=dp[x]+1;
        }
    }

    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>y) swap(x,y);
        int ans=0;
        for(int i=x;i<=y;i++) ans=max(ans,dp[i]);
        printf("Case #%d:\n%d\n",cs,ans);
    }

    return 0;
}

