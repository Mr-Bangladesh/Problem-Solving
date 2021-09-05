#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000000+7
#define MAXX 5000000
vector<ll> Primes; bool Ar[MAXX+5];
void sieve(){
    Ar[0]=1; Ar[1]=1;
    for (ll i = 2; i <= MAXX; i++) {
        if(Ar[i] == false) {
            Primes.push_back(i);
            for (ll j = 2 * i; j <= MAXX; j = j + i) {
                Ar[j] = true;
            }
        }
    }
}
//double mysqrt(ll N){
//    double high,low,mid; high=(double)N;low=0.0;for(ll i=1;i<=64;i++){ mid=(high+low)/2; if(mid*mid>N) high=mid; else low=mid;}
//    return mid;}
//ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
//ll bigmod(ll B,ll P,ll M){ if(P==0) return 1; else if(P%2==0) { ll R=bigmod(B,P/2,M); return ((R%M)*(R%M))%M;}
//    else { ll R=bigmod(B,P-1,M); return ((R%M)*(B%M))%M;}
//}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll power(ll B,ll P){ if(P==0) return 1; ll X=power(B,P/2); if(P%2==0) return X*X; else return B*X*X;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

ull A[5000005];

ll lim=5000000;

void F()
{
    for(ll i=2;i<=lim;i++) A[i]=i;

    ll x=Primes.size();

    for(ll i=0;i<x;i++)
    {
        ll U=Primes[i];

        for(ll j=U;j<=lim;j+=U)
        {
            A[j]=(A[j]*(U-1))/U;
        }
    }
}

void PRE()
{
    for(ll i=2;i<=lim;i++)
    {
        A[i]+=A[i-1];
    }
}

int main()
{
    sieve();

    F();

    PRE();

    ll T,N,M,X,Y,W;

    scanf("%lld",&T);

    for(ll C=1;C<=T;C++)
    {
        scanf("%lld %lld",&X,&Y);

        ull ans=A[Y]-A[X-1];

        //cout<<A[Y]<<" "<<A[X-1]<<endl;

        printf("%llu\n",ans);
    }

    return 0;
}



