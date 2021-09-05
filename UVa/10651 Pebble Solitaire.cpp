#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000000+7
#define PI 2*acos(0.0)
//#define MAXX 10000000
//vector<ll> Primes; ll isprime[MAXX+2]; bool Ar[MAXX+100];
//void sieve(){
//    Ar[0]=1; Ar[1]=1;
//    for (ll i = 2; i <= MAXX; i++) {
//        if(Ar[i] == false) {
//            Primes.push_back(i);
//            isprime[i]=1;
//            for (ll j = 2 * i; j <= MAXX; j = j + i) {
//                Ar[j] = true;
//            }
//        }
//    }
//}
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

ll SET(ll N,ll pos){
    return (N | (1<<pos));
}
ll RESET(ll N,ll pos){
    return (N & ~(1<<pos));
}
bool check(ll N,ll pos){
    return (bool) (N & (1<<pos));
}
ll dp[1<<13];
ll F(ll N){
    if(dp[N]!=-1) return dp[N];
    ll Min=INF;
    for(int i=0;i<12;i++){
        if(!check(N,i)){
            if(i>1 && check(N,i-1)==1 && check(N,i-2)==1){
                ll tmp=N;
                N=SET(N,i);
                N=RESET(N,i-1);
                N=RESET(N,i-2);
                Min=min(Min,F(N));
                N=tmp;
            }
            if(i<10 && check(N,i+1)==1 && check(N,i+2)==1){
                ll tmp=N;
                N=SET(N,i);
                N=RESET(N,i+1);
                N=RESET(N,i+2);
                Min=min(Min,F(N));
                N=tmp;
            }
        }
    }
    ll Count=0;
    for(int i=0;i<12;i++){
        if(check(N,i)) Count++;
    }
    return dp[N]=min(Min,Count);
}
int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    cin>>T;
    while(T--){
        string S;
        cin>>S;
        X=0;
        for(int i=0;i<12;i++){
            if(S[i]=='o') X=SET(X,i);
        }
        memset(dp,-1,sizeof(dp));
        ll ans=F(X);
        cout<<ans<<endl;
    }

    return 0;
}

