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
map<ll, vector< pair<ll,ll> > > G;
ll T[100006],L[100006],mark[100005],Dist[100005];

//void DFS(ll source)
//{
//    stack <ll> S;
//    T[source]=1;
//    mark[source]=1;
//    Dist[source]=0;
//    S.push(source);
//    ll v;
//    bool check=false;
//
//    while(!S.empty())
//    {
//        int u=S.top();
//        check=false;
//        for(int i=0;i<G[u].size();i++)
//        {
//            //cout<<u<<" "<<G[u].size()<<endl;
//            v=G[u][i].first;
//            //if(u==1) cout<<v<<" "<<i<<endl;
//            if(mark[v]==0)
//            {
//                //cout<<u<<" "<<v<<endl;
//                check=true;
//                mark[v]=1;
//                S.push(v);
//                T[v]=u;
//                L[v]=L[u]+1;
//                Dist[v]=Dist[u]+G[u][i].second; //cout<<"Visited "<<v<<" "<<Dist[v]<<endl;
//                break;
//            }
//
//            if(mark[v]!=0 && check==false)
//            {
//                mark[v]=2;
//                S.pop();
//            }
//        }
//
//
//    }
//}
ll Parent[100005][70];
void dfs(ll u , ll p , ll d){
    mark[u] = true ;
    T[u] = p ; L[u] = d ;
    for(int i=0;i<G[u].size();i++){
        ll v = G[u][i].first; ll w =G[u][i].second;
        if( mark[v] ) continue;
        Dist[v] = Dist[u] + w ;
        //Parent[v][0] = u ;
        dfs(v,u,d+1);
    }
}

void pre(ll N)
{
    for(ll i=0;i<N;i++)
    {
        Parent[i][0]=T[i];
    }

    Parent[0][0]=-1;

    for(ll j=1;(1<<j)<N;j++)
    {
        for(ll i=0;i<N;i++)
        {
            if(Parent[i][j-1]==-1)
            {
                Parent[i][j]=-1;
            }
            else{
                Parent[i][j]=Parent[Parent[i][j-1]][j-1];
            }
        }
    }
}

ll lca(ll U,ll V)
{
    if(L[U] < L[V]) swap(U,V);

    ll lg = log2(L[U]);

    for(ll i = lg; i >= 0; i--){
        if(L[U] - (1 << i) >= L[V]){
            U = Parent[U][i];
        }
    }

    if( U == V ) return U;
    for(ll i = lg; i >= 0; i--)
        if(Parent[U][i] != -1 && Parent[U][i] != Parent[V][i]){
            U = Parent[U][i];
            V = Parent[V][i];
        }
    return T[V];
}

int main()
{
    ///use always ll instead of ll
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll N,M,X,Y,W,K,Q,R,P;

    while(cin>>N){
        if(!N) break;
        for(ll i=1;i<N;i++){
            cin>>X>>Y;
            G[i].pb(mp(X,Y));
            G[X].pb(mp(i,Y));
        }
        //DFS(0);
        dfs(0,-1,0);
        //for(int i=0;i<G[1].size();i++) cout<<G[1][i].first<<" "; cout<<endl;

        //for(int i=0;i<N;i++) cout<<i<<" "<<Dist[i]<<endl;

        //cout<<G[0].size()<<endl;

        pre(N);
        cin>>Q;
        for(ll i=1;i<=Q;i++){
            ll U, V;
            cin>>U>>V;
            ll l=lca(U,V);
            ll ans=Dist[U]+Dist[V]-2*Dist[l];
            //cout<<U<<" "<<V<<" "<<l<<" "<<ans<<endl;
            cout<<ans; if(i<Q) cout<<" ";
        }cout<<endl;

        memset(Parent,0,sizeof(Parent));
        memset(T,0,sizeof(T));
        memset(L,0,sizeof(L));
        G.clear();
        memset(mark,0,sizeof(mark));
    }

    return 0;
}

