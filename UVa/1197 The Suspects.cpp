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

map<ll,vector<ll> > G;

int Count=0;

map<ll,ll> Mark;

void DFS(int U)
{
    Mark[U]=1;
    Count++;
    for(int i=0;i<G[U].size();i++)
    {
        ll V=G[U][i];

        if(!Mark[V])
        {
            Mark[V]=1;
            DFS(V);
        }
    }
}

int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("1.txt","r",stdin);

    ll T,N,M,X,Y,W,K;

    while(cin>>N>>M)
    {
        if(N==0 && M==0) break;

        for(int i=1;i<=M;i++)
        {
            cin>>K;

            int A[K+2];

            for(int j=1;j<=K;j++)
            {
                cin>>A[j];
            }
            for(int j=2;j<=K;j++)
            {
                G[A[j]].pb(A[j-1]);
                G[A[j-1]].pb(A[j]);
            }
        }

        DFS(0);

        cout<<Count<<endl;

        Count=0;
        G.clear(); Mark.clear();
    }

    return 0;
}



