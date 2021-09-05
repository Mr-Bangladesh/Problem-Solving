#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll pow(ll B,ll P) { ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;}
int fx4[]={1,-1,0,0}; int fy4[]={0,0,1,-1};

#define MAX 2000
vector<ll> primes;
ll prime[10000];
ll A[MAX+100];
void sieve()
{
    primes.push_back(2);
    prime[2]=1;

    for(int i=2;i<=MAX;i+=2) A[i]=1;

    for(int i=3;i<=MAX;i+=2)
    {
        if(A[i]==0)
        {
            primes.push_back(i);
            prime[i]=1;
            for(int j=i*i;j<=MAX;j+= i*2) A[j]=1;
        }

    }
}

ll DP[205][20][1200];
ll N,K;

ll F(ll i,ll Count,ll Sum)
{
    if(i>=200) return 0;

    if(Sum==0 && Count==K) return 1;

    if(Sum<0) return 0; if(Count>K) return 0;

    if(DP[i][Count][Sum]!=-1) return DP[i][Count][Sum];

    ll R1=0,R2=0;

    if(Sum-primes[i]>=0)
    {
        R1=F(i+1,Count+1,Sum-primes[i]);
    }
    R2=F(i+1,Count,Sum);

    return DP[i][Count][Sum]=R1+R2;

}

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    sieve();

    while(scanf("%lld %lld",&N,&K))
    {
        if((N|K)==0) break;

        memset(DP,-1,sizeof(DP));

        ll ans=F(0,0,N);

        printf("%lld\n",ans);
    }

    return 0;
}
