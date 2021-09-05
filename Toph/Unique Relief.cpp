/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
vector<ll> Primes;
ll const MAX = 10000;
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
ll dp[10004][1230];
ll ans=0,N;
ll f(ll sum,ll idx){
    if(sum==0) return 0;
    if(idx>=N || sum<0) return INT_MIN;
    if(dp[sum][idx]!=-1) return dp[sum][idx];
    ll r1=1+f(sum-Primes[idx],idx+1);
    ll r2=f(sum,idx+1);
    return dp[sum][idx]=max(r1,r2);
}
int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    sieve();
    N=Primes.size();
    memset(dp,-1,sizeof(dp));
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ll ans=max(0,f(n,0));
        printf("%lld\n",ans);
    }

    return 0;
}


