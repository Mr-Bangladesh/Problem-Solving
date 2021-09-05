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
map<ll, pair<double,double> > V;
ll mark[800][800];
struct ff{
    ll u,v; double w;
    ff(ll a,ll b,double c){
        u=a; v=b; w=c;
    }
};
bool faizul(ff a,ff b){
    return a.w<b.w;
}
vector<ff> G;
ll Parent[1000];
void init(ll N){
    for(int i=1;i<=N;i++) Parent[i]=i;
}
ll Find(ll r){
    if(r==Parent[r]) return r;
    return Parent[r]=Find(Parent[r]);
}

vector< pair<ll,ll> > ans;

void kruskal(){
    sort(G.begin(),G.end(),faizul);
    for(int i=0;i<G.size();i++){
        ll x=G[i].u; ll y=G[i].v; double w=G[i].w;
        //cout<<x<<" "<<y<<" "<<w<<endl;
        ll px=Find(x); ll py=Find(y);

        if(px!=py){
            Parent[px]=py;
            if(w>0.00) ans.pb(mp(px,py));
        }
    }
}

int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    cin>>T;

    while(T--){
        cin>>N;
        double x,y;
        for(int i=1;i<=N;i++){
            cin>>x>>y;
            V[i]={x,y};
        }

        init(N);

        cin>>M;
        for(int i=1;i<=M;i++){
            cin>>X>>Y;
            mark[X][Y]=1;
            mark[Y][X]=1;
        }

        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                double d1=V[i].first-V[j].first, d2=V[i].second-V[j].second;
                double d=sqrt(d1*d1 + d2*d2);
                if(mark[i][j]){
                    d=0.00;
                }
                G.pb(ff(i,j,d));
                //cout<<i<<" "<<j<<" "<<d<<endl;
            }
        }
        kruskal();

        if(ans.size()==0){
            cout<<"No new highways need"<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        cout<<endl;
        ans.clear(); G.clear(); V.clear();
        memset(mark,0,sizeof(mark));
    }

    return 0;
}

