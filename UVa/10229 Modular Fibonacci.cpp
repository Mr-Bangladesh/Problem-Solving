#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define PHI 1.6180339
//#define MAXX 10000000
//vector <ll> Primes;
//ll status[MAXX/32];
//bool check(ll N,ll pos){
//    return (bool) (N & (1<<pos));
//}
//ll SET(ll N,ll pos){
//    return (N  (1<<pos));
//}
//void Bitwise_seive(){
//    Primes.push_back(2);
//    for(ll i=3;i<=MAXX;i+=2){
//        if(check(status[i/32],i%32)==0){
//            Primes.push_back(i);
//            for(ll j=i*i;j<=MAXX;j+= i*2){
//                status[j/32]=SET(status[j/32],j%32);
//            }
//        }
//    }
//}
////double mysqrt(ll N){
//    double high,low,mid; high=(double)N;low=0.0;for(ll i=1;i<=64;i++){ mid=(high+low)/2; if(mid*mid>N) high=mid; else low=mid;}
//    return mid;}
//ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}

///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll power(double B,ll P,ll mod){
    if(P==0) return 1;
    ll X=power(B,P/2,mod);
    if(P%2==0) return (X*X)%mod;
    else{
        ll x=round(B*X);
        return ((x%mod)*(X%mod))%mod;
    }
}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

ll fib[]={0,1,1,2,3,5};

ll F(ll N,ll mod){
    if(N<6){
        return (fib[N]%mod);
    }
    ll ans=5;
    ans=ans*power(PHI,N-5,mod);
    return ans%mod;
}

int main()
{
    //Bitwise_seive();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    while(cin>>N>>M){
        cout<<F(N,(1LL<<M))<<endl;
    }

    return 0;
}

