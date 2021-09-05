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

ll A[200000];

map<ll, vector <ll> > G;
map<ll,ll> Mark;
ll Count=0;

void DFS(ll U)
{
    Mark[U]=1;
    Count+=A[U];
    for(int i=0;i<G[U].size();i++)
    {
        ll V=G[U][i];

        if(Mark[V]==0)
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

    ll T,N,M,X,Y,W;

    //freopen("1.txt","r",stdin);

    cin>>T;

    while(T--)
    {
        cin>>N>>M;

        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        for(int i=1;i<=M;i++)
        {
            cin>>X>>Y;
            G[X].pb(Y);
            G[Y].pb(X);
        }

        bool check=true;

        for(int i=0;i<N;i++)
        {
            if(Mark[i]==0)
            {
                DFS(i);
                //cout<<i<<" "<<Count<<endl;
                if(Count!=0)
                {
                    check=false; break;
                }
                Count=0;
            }
        }

        if(check) cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;

        G.clear();
        Mark.clear();
        Count=0;
        memset(A,0,sizeof(A));
    }

    return 0;
}



