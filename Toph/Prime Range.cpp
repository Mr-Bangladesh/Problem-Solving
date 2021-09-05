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

ll a[5761457];
int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    sieve();
    x=Primes.size();
    a[0]=0;
    a[1]=Primes[0];
    //cout<<"O K"<<endl;
    for(int i=2;i<=x;i++){
        a[i]=a[i-1]+Primes[i-1];
    }

    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&x,&y);
        if(x>y) swap(x,y);
        ll ans=a[y]-a[x-1];
        //cout<<a[y]<<" "<<a[x-1]<<" "<<a[x]<<endl;
        printf("%lld\n",ans);
    }

    return 0;
}


