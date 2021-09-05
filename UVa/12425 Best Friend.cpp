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

#define MAX 1000001
vector<ll> Primes;
ll least[MAX];
void linearsieve(){
    for(ll i=2;i<MAX;i++){
        if(!least[i]){
            least[i]=i;
            Primes.pb(i);
        }
        for(ll x:Primes){
            if(x>least[i] | i*x>=MAX) break;
            least[i*x]=x;
        }
    }
}

ll phi(ll N){
    ll ans=N;
    for(int i=0;i<Primes.size() && Primes[i]*Primes[i]<=N;i++){
        if(N%Primes[i]==0){
            ans=(ans*(Primes[i]-1))/Primes[i];
        }
        while(N%Primes[i]==0){
            N=N/Primes[i];
        }
    }
    if(N!=1){
        ans=(ans/N)*(N-1);
    }
    return ans;
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    linearsieve();
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        ll n,q;
        scanf("%lld %lld",&n,&q);
        vector<ll> v,p;
        ll x=sqrt(n);
        for(ll i=1;i<=x;i++){
            if(n%i) continue;
            if(i==n/i) v.pb(i);
            else{
                v.pb(i);
                v.pb(n/i);
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            p.pb(phi(n/v[i]));
        }
        for(int i=1;i<v.size();i++){
            p[i]+=p[i-1];
        }
        printf("Case %d\n",cs++);
        while(q--){
            ll x;
            scanf("%lld",&x);
            if(x<=0){
                printf("0\n");
                continue;
            }
            ll i=upper_bound(v.begin(),v.end(),x)-v.begin(); i--;
            printf("%lld\n",p[i]);
        }
    }

    return 0;
}


