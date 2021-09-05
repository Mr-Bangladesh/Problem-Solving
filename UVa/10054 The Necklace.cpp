#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
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

map<ll, vector<ll> > G;

map<ll,ll> Mark,isloop,Parent;

set<ll> S;

vector < pair<ll,ll> > ans;

ll last=0;

void DFS(ll U)
{
    Mark[U]=1;

    for(int i=0;i<G[U].size();i++)
    {
        ll V=G[U][i];

        if(Mark[V]==0)
        {
            Mark[V]=1;

            Parent[V]=U; ans.pb(mp(U,V));

            if(isloop[V]==1) ans.pb(mp(V,V));

            last=V;

            DFS(V);
        }
    }
}

int main()
{
    ///use always ll instead of int
    //sieve();

    ll T,N,M,X,Y,W,C=1;

    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    scanf("%lld",&T);

    while(T--)
    {
        printf("Case #%lld\n",C++);
        scanf("%lld",&N);

        for(int i=1;i<=N;i++)
        {
            scanf("%lld %lld",&X,&Y);

            S.insert(X);
            S.insert(Y);

            if(X==Y) isloop[X]=1;

            if(X==Y) continue;

            G[X].pb(Y);
            G[Y].pb(X);

        }

        bool check=true;

        for(auto it=S.begin();it!=S.end();it++)
        {
            ll V=*it;

            if(G[V].size()!=2)
            {
                check=false; break;
            }
        }

        if(check==false)
        {
            printf("some beads may be lost\n");
        }
        else{
            auto it=S.begin();
            DFS(*it);
            ans.pb(mp(last,*it));

            if(ans.size()!=N)
                printf("some beads may be lost\n");
            else{
                for(int i=0;i<N;i++) printf("%lld %lld\n",ans[i].first,ans[i].second);
            }
        }

        if(T) printf("\n");

        G.clear();
        Mark.clear(); S.clear(); isloop.clear(); Parent.clear();

    }

    return 0;
}



