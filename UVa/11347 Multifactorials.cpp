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
ll const MAX = 1005;
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

map<int,int> cnt[1004];

void pf(int n){
    int idx=n;
    for(int i=0;Primes[i]*Primes[i]<=n;i++){
        if(n%Primes[i]) continue;
        while(n%Primes[i]==0){
            cnt[idx][Primes[i]]++;
            n/=Primes[i];
        }
    }
    if(n!=1){
        cnt[idx][n]++;
    }
}

int main()
{
    sieve();

    for(int i=2;i<=1000;i++) pf(i);

//    for(auto it:cnt[360]){
//        cout<<it.first<<" "<<it.second<<endl;
//    }
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        string s;
        cin>>s;
        int n=0,k=0;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='!') k++;
            else n=n*10+(s[i]-48);
        }
        map<int,int> tmp;
        for(int i=n;i>=2;i-=k){
            for(auto it:cnt[i]){
                tmp[it.first]+=it.second;
            }
        }
        bool check=true;
        double x=0;
        for(auto it:tmp){
            //cout<<it.first<<" "<<it.second<<endl;
            x+=log10(it.second+1);
        }
        int y=ceil(x);
        if(y>18){
            printf("Case %d: Infinity\n",cs);
            continue;
        }
        ll sum=1;
        for(auto it:tmp){
            sum*=(it.second+1);
        }
        printf("Case %d: %lld\n",cs,sum);
    }

    return 0;
}

