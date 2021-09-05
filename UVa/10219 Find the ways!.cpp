#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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

ll digit(ll N,ll i){
    double d=0.00;
    for(ll j=i;j<=N;j++){
        d+=log10(j);
    }
    return floor(d)+1;
}

int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    while(cin>>N>>M){

        X=N-M;

        ll xx=M;

        vector<ll> V;

        if(X<M)  swap(X,M);

            for(ll i=X+1;i<=N;i++) V.pb(i);
            queue<ll> Q;
            for(ll i=2;i<=M;i++) Q.push(i);
            while(!Q.empty()){
                    ll i=Q.front();
                    //cout<<i<<endl;
                    Q.pop();
                for(int j=0;j<V.size();j++){
                    if(V[j]%i==0){
                        //cout<<"vag "<<i<<" "<<V[j]<<endl;
                        V[j]=V[j]/i;
                        break;
                    }
                    else{
                        ll gcd=__gcd(V[j],i);
                        V[j]/=gcd;
                        //cout<<gcd<<" "<<i<<" "<<V[j]<<endl;
                        if(gcd!=1){
                            Q.push(i/gcd);
                            //cout<<"push" <<i<<" "<<i/gcd<<" "<<V[j]*gcd<<endl;
                            break;
                        }
                        //break;
                    }
                }
            }
            double ans=0.00;
            for(int i=0;i<V.size();i++){
                ans+=log10(V[i]);
            }
        ll res=floor(ans)+1;
        cout<<res<<endl;
    }

    return 0;
}

