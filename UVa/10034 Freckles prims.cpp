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
double mysqrt(ll N){
    double high,low,mid; high=(double)N;low=0.0;for(ll i=1;i<=64;i++){ mid=(high+low)/2; if(mid*mid>N) high=mid; else low=mid;}
    return mid;}
//ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
//ll bigmod(ll B,ll P,ll M){ if(P==0) return 1; else if(P%2==0) { ll R=bigmod(B,P/2,M); return ((R%M)*(R%M))%M;}
//    else { ll R=bigmod(B,P-1,M); return ((R%M)*(B%M))%M;}
//}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll power(ll B,ll P){ if(P==0) return 1; ll X=power(B,P/2); if(P%2==0) return X*X; else return B*X*X;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

map<ll, vector< pair<ll,double> > > G;

struct edge{
    ll At; double cost;
    edge(ll a,double b)
    {
        At=a; cost=b;
    }
};

bool operator<(edge a,edge b)
{
    return a.cost>b.cost;
}

map<ll,double> Dist;
map<ll,ll> Mark;

double Prims(ll N)
{
    priority_queue<edge> PQ; PQ.push(edge(0,0.0));

    for(int i=0;i<N;i++) Dist[i]=(double)INF;

    Dist[0]=0.0;

    double ans=0.0;

    while(!PQ.empty())
    {
        edge E=PQ.top(); PQ.pop();
        ll U=E.At;

        if(Mark[U]) continue;

        Mark[U]=1; ans+=E.cost;

        for(int i=0;i<G[U].size();i++)
        {
            ll V=G[U][i].first;

            if(Mark[V]) continue;

            double W=G[U][i].second;

            if(W<Dist[V])
            {
                Dist[V]=W;
                PQ.push(edge(V,Dist[V]));
            }
        }
    }

    return ans;

}

int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    cin>>T;

    while(T--)
    {
        cin>>N;

        double U,V;

        vector < pair<double,double> > points;

        for(int i=1;i<=N;i++)
        {
            cin>>U>>V;
            points.pb(mp(U,V));
        }

        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                U=points[i].first-points[j].first;
                V=points[i].second-points[j].second;

                double D=sqrt(U*U+V*V);

                G[i].pb(mp(j,D));
                G[j].pb(mp(i,D));
            }
        }

        double ans=Prims(N);

        printf("%.2f\n",ans);

        if(T) printf("\n");

        G.clear(); Mark.clear(); Dist.clear();
    }

    return 0;
}

