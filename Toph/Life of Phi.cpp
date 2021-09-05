#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
const ll maxx=1000009;
int status[(maxx>>5)+2];
bool isprime[1000009];
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
    isprime[2]=1;
    for(int i=3;i<=maxx;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            Primes.pb(i);
            isprime[i]=1;
            if(i<=sqrtN)
            for(j=i*i;j<=maxx;j+=(i<<1))
            {
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    sieve();

    scanf("%lld",&t);

    while(t--){
        scanf("%lld",&n);
        ll tmp=n;
        if(isprime[n]){
            printf("0\n"); continue;
        }
        ll ans=n*n,lob=1,hor=1;
        for(int i=0;i<Primes.size() && Primes[i]*Primes[i]<=n;i++){
            if(n%Primes[i]) continue;
            while(n%Primes[i]==0){
                n/=Primes[i];
            }
            lob*=(Primes[i]-1);
            hor*=Primes[i];
        }
        if(n!=1){
            lob*=(n-1);
            hor*=n;
        }
        ans*=lob;
        ans/=hor;
        ans/=2;
        ll res=(tmp*(tmp-1))/2;
        //cout<<ans<<endl;
        printf("%lld\n",res-ans);
    }

    return 0;
}



