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

vector<ll> pdiv[30005];
ll const MAX = 30001;
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
map<ll,ll> cnt;
int main()
{
    sieve();

    ll n;
    cin>>n;
    ll a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    ll res=0;

    for(int i=1;i<=n;i++){
        ll sz=pdiv[a[i]].size();
        for(ll j=1;j<(1<<sz);j++){
            ll b=__builtin_popcount(j);
            ll cur=1;
            for(ll k=0;k<sz;k++){
                if(j&(1<<k)){
                    cur*=pdiv[a[i]][k];
                }
            }
            if(b%2 && cnt[cur]>1){
                res+=cnt[cur];
            }
            else if(b%2==0 && cnt[cur]>1){
                res-=cnt[cur];
            }
            cout<<res<<" "<<cur<<endl;
            cnt[cur]++;
        }

    }
    ll tot=(n*(n-1))/2;
    cout<<res<<endl;
    cout<<tot-res<<endl;

    return 0;
}


