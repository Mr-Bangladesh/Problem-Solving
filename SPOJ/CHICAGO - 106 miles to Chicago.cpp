#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

map<ll,vector< pair<ll,ll> > > g;
map<ll,double> d;

void dijkstra(ll n){
    for(int i=1;i<=n;i++) d[i]=0.000;
    priority_queue< pair<double,ll> > pq;
    pq.push(mp(1.00,1));
    d[1]=1.00;
    while(!pq.empty()){
        auto u=pq.top(); pq.pop();
        if(u.first!=d[u.second]) continue;
        for(auto v:g[u.second]){
            double p=(u.first*v.second)/100.00;
            if(d[v.first]<p){
                d[v.first]=p;
                pq.push(mp(p,v.first));
            }
        }
    }
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    while(cin>>n){
        if(!n) break;
        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>w;
            g[x].pb(mp(y,w));
            g[y].pb(mp(x,w));
        }
        dijkstra(n);
        printf("%.6f percent\n",d[n]*100.00);
        g.clear();
        d.clear();
    }

    return 0;
}



