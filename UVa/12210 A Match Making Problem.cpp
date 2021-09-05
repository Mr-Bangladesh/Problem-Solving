#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
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
//ll bigmod(ll B,ll P,ll M){ if(P==0) return 1; else if(P%2==0) { ll R=bigmod(B,P/2,M); return ((R%M)*(R%M))%M;}
//    else { ll R=bigmod(B,P-1,M); return ((R%M)*(B%M))%M;}
//}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll power(ll B,ll P){ if(P==0) return 1; ll X=power(B,P/2); if(P%2==0) return X*X; else return B*X*X;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    //Bitwise_seive();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    ll C=1;
    while(cin>>N>>M){
        if(N==0 && M==0) break;
        ll ans=INF;
        for(int i=1;i<=N;i++){
            cin>>X;
            ans=min(ans,X);
        }
        for(int i=1;i<=M;i++){
            cin>>X;
        }
        if(N<=M){
            printf("Case %lld: 0\n",C);
        }
        else{
            printf("Case %lld: %lld %lld\n",C,N-M,ans);
        }
        C++;
    }

    return 0;
}


