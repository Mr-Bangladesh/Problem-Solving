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
const ll maxx=10000;
int status[(maxx>>5)+2];

bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N, int pos)
{
    return N=(N|(1<<pos));
}
vector<ll>Primes;
void sieve()
{
    ll i,j,sqrtN;
    sqrtN=ll(sqrt(maxx))+1;
    Primes.pb(2);
    for(int i=3;i<=maxx;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            Primes.pb(i);

            if(i<=sqrtN)
            for(j=i*i;j<=maxx;j+=(i<<1))
            {
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
}

ll f(ll n){
    bool first=false;
    ll gcd=1;
    for(ll i=0;Primes[i]*Primes[i]<=n;i++){
        if(n%Primes[i]) continue;
        ll cnt=0;
        while(n%Primes[i]==0){
            cnt++;
            n/=Primes[i];
        }
        if(first){
            gcd=__gcd(gcd,cnt);
        }
        else{
            gcd=cnt; first=true;
        }
    }
    if(n!=1){
        return 1;
    }
    return gcd;
}
ll res[1000005];
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);
    sieve();
    ll t,n,m,x,y,w,k,q,r,p,cs;
    for(int i=2;i<=1000000;i++){
        res[i]=f(i);
    }
    cin>>t;
    for(cs=1;cs<=t;cs++){
        cin>>x>>y;
        ll ans=res[x]*y;
        printf("Case #%lld: %lld\n",cs,ans);
    }

    return 0;
}
