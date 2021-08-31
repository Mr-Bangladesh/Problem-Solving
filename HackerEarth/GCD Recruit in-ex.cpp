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
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

vector<ll> pdiv[3005];
ll const MAX = 3001;
bitset<MAX> prime;
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for(ll i = 2; i < MAX; ++i){
        if(prime[i]){
            for(ll j=i;j<MAX;j+=i){
                pdiv[j].pb(i);
                prime[j]=0;
            }
        }
    }
}


int main()
{
    sieve();

    int n;
    cin>>n;
    ll a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    map<ll,ll> cnt;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll cur=a[i];
        int sz=pdiv[cur].size();
        for(int j=1;j<(1<<sz);j++){
            int b=__builtin_popcount(j);
            ll num=1;
            for(int k=0;k<sz;k++){
                if(j&(1<<k)){
                    num*=pdiv[cur][k];
                }
            }
            if(b%2){
                ans+=(cnt[num]);
            }
            else{
                ans-=cnt[num];
            }
            cnt[num]++;
        }
    }

    cout<<ans<<endl;

    return 0;
}


