#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
const ll maxx=10000000;
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
    ll phi=n,nod=1;
    ll ans=n;
    for(int i=0;Primes[i]*Primes[i]<=n;i++){
        if(n%Primes[i]) continue;
        ll cnt=0;
        while(n%Primes[i]==0){
            cnt++;
            n/=Primes[i];
        }
        nod*=(cnt+1);
        phi*=(Primes[i]-1);
        phi/=Primes[i];
    }
    if(n!=1){
        nod*=2;
        phi*=(n-1);
        phi/=n;
    }
    //cout<<ans<<" "<<phi<<" "<<nod<<endl;
    ans-=phi;
    ans-=(nod-1);
    return ans;
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    sieve();

    while(cin>>n){
        if(n<=1){
            cout<<0<<endl;
            continue;
        }
        ll ans=f(n);
        cout<<ans<<endl;
    }

    return 0;
}
