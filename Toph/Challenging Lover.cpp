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
#define MAXX 10000000
vector <ll> Primes;
ll status[MAXX/32];
bool check(ll N,ll pos){
    return (bool) (N & (1<<pos));
}
ll SET(ll N,ll pos){
    return (N | (1<<pos));
}
void sieve(){
    Primes.pb(2);
    for(ll i=3;i<=MAXX;i+=2){
        if(check(status[i/32],i%32)==0){
            Primes.pb(i);
            for(ll j=i*i;j<=MAXX;j+= i*2){
                status[j/32]=SET(status[j/32],j%32);
            }
        }
    }
}

ll power(ll B,ll P){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=power(B,P/2);
        return ((R)*(R));
    }
    else{
        ll R=power(B,P-1);
        return ((R)*(B));
    }
}
ll SOD(ll N)
{
    ll X=1,Y=1;
    for(int i=0;Primes[i]*Primes[i]<=N;i++)
    {
        ll Count=0;
        while(N%Primes[i]==0)
        {
            Count++;
            N=N/Primes[i];
        }
        if(Count)
        {
            X=X*(power(Primes[i],Count+1)-1);
            Y=Y*(Primes[i]-1);
        }
    }
    if(N!=1)
    {
        X=X*(N*N-1);
        Y=Y*(N-1);
    }
    return X/Y;
}

int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    sieve();
    cin>>t;
    while(t--){
        cin>>n;
        x=SOD(n);
        if(binary_search(Primes.begin(),Primes.end(),x)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}

