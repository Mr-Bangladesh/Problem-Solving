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
vector<ll> V;
ll idx,DP[50][5000];
bool F(ll I,ll W){
    if(I>idx || W<0) return 0;
    if(W==0) return 1;
    if(DP[I][W]!=-1) return DP[I][W];
    ll P1=0,P2=0;
    if(W-V[I]>=0){
        P1=F(I+1,W-V[I]);
    }
    P2=F(I+1,W);
    return P1|P2;
}
int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    cin>>T;
    cin.ignore();
    string S;
    while(T--){
            //cin.ignore();
        getline(cin,S);
        S+=" ";
        int len=S.length();
        X=0;
        V.clear();
        V.pb(0);
        ll sum=0;
        for(int i=0;i<len;i++){
            if(S[i]==32){
                V.pb(X); sum+=X;
                X=0;
            }
            else X=X*10+(S[i]-48);
        }
    //cout<<S<<" "<<sum<<" "<<V.size()<<" ";
        if(sum%2){
            cout<<"NO"<<endl;
            continue;
        }
        idx=V.size()-1;
        memset(DP,-1,sizeof(DP));
        bool ans=F(1,sum/2); V.clear();
        //cout<<S<<" ";

        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        V.clear();idx=0;
        S="";
    }

    return 0;
}

