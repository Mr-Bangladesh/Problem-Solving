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
const ll maxx=1000000;
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
ll isprime[maxx+5];
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
ll mod1=1000000000;
map<ll,ll> cnt;
ll ans[1000005];
ll mul=1;
void F(ll N){
    ll I=N;
    //if(I==18) cout<<mul<<" "<<endl;
    for(int i=0;Primes[i]*Primes[i]<=N;i++){
        if(N%Primes[i]) continue;
        ll c=0;
        while(N%Primes[i]==0){
            N/=Primes[i];
            c++;
            //if(I==18) cout<<"gun"<<Primes[i]<<" "<<c<<" "<<cnt[Primes[i]]<<endl;
            if(c>cnt[Primes[i]]){
                cnt[Primes[i]]=c;
                mul*=Primes[i];
            }
        }
        //cout<<I<<" "<<Primes[i]<<" "<<cnt[Primes[i]]<<endl;
        //if(I==18) cout<<c<<" "<<Primes[i]<<" "<<cnt[Primes[i]]<<endl;
    }

    //if(I==18) cout<<N<<endl;

    if(N!=1){
        if(cnt[N]==0){
            mul*=N;
            cnt[N]=1;
        }
    }

    //cout<<I<<" "<<mul<<endl;

    while(mul%10==0) mul/=10;

    //cout<<I<<" "<<mul<<endl;

    mul=mul%mod1;
    ans[I]=mul%10;

}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    sieve();
    ans[1]=1;
    for(int i=2;i<=1000000;i++){
        F(i);
    }

    while(cin>>N){
        if(!N) break;
        cout<<ans[N]<<endl;
    }

    return 0;
}

