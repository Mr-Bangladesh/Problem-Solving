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

ll D[50],V[50],DP[50][1005],T,W,N,dir[50][1005];

ll F(ll I,ll w)
{
    if(I>N) return 0;

    if(DP[I][w]!=-1) return DP[I][w];

    ll P1=0,P2=0;

    if(w+3*W*D[I]<=T) P1=V[I]+F(I+1,w+3*W*D[I]);

    P2=F(I+1,w);

    if(P1>P2)
    {
        dir[I][w]=1;
        return DP[I][w]=P1;
    }
    else{
        dir[I][w]=2;
        return DP[I][w]=P2;
    }
}

vector<pair<ll,ll> > ans;

void print(ll I,ll w)
{
    if(dir[I][w]==-1) return;

    else if(dir[I][w]==1){
        ans.pb(mp(D[I],V[I]));
        print(I+1,w+3*W*D[I]);

    }
    else{
        print(I+1,w);
    }
}

int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    while(cin>>T>>W){
        cin>>N;

        for(int i=1;i<=N;i++) cin>>D[i]>>V[i];
        memset(DP,-1,sizeof(DP));
        memset(dir,-1,sizeof(dir));

        ll xx=F(1,0);
        print(1,0);

        cout<<xx<<endl;

        cout<<ans.size()<<endl;

        for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;

        ans.clear();
        memset(D,0,sizeof(D));
        memset(V,0,sizeof(V));
    }

    return 0;
}

