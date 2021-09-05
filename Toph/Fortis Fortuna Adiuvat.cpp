/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
struct node{
    ll At,Cost; node(ll a,ll b){At=a;Cost=b;}
};
bool operator<(node a,node b)
{
    return a.Cost>b.Cost;
}
vector< pair<ll,ll> > g[100006],g1[100006];
ll d[100006],d1[100006];

void dijkstra(ll s,ll n){
    for(int i=0;i<=n;i++) d[i]=INF;
    priority_queue<node> pq;
    pq.push(node(s,0));
    d[s]=0;
    while(!pq.empty()){
        auto u=pq.top(); pq.pop();
        if(u.Cost!=d[u.At]) continue;
        for(auto v:g[u.At]){
            if(d[u.At]+v.second<d[v.first]){
                d[v.first]=d[u.At]+v.second;
                pq.push(node(v.first,d[v.first]));
            }
        }
    }
}
void dijkstra1(ll s,ll n){
    for(int i=0;i<=n;i++) d1[i]=INF;
    priority_queue<node> pq;
    pq.push(node(s,0));
    d1[s]=0;
    while(!pq.empty()){
        auto u=pq.top(); pq.pop();
        if(u.Cost!=d1[u.At]) continue;
        for(auto v:g1[u.At]){
            if(d1[u.At]+v.second<d1[v.first]){
                d1[v.first]=d1[u.At]+v.second;
                pq.push(node(v.first,d1[v.first]));
            }
        }
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs,s;
    cin>>t;
    for(cs=1;cs<=t;cs++){
        cin>>n>>m>>s>>q;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>w;
            g[x].pb(mp(y,w));
            g1[y].pb(mp(x,w));
        }
        dijkstra(s,n);
        dijkstra1(s,n);
//        for(int i=1;i<=n;i++) cout<<i<<" "<<d[i]<<endl;
//        cout<<endl;
//        for(int i=1;i<=n;i++) cout<<i<<" "<<d1[i]<<endl;
        cout<<"Case "<<cs<<":"<<endl;
        while(q--){
            cin>>x>>y;
            if(d1[x]==INF || d[y]==INF){
                cout<<"Be seeing ya, John"<<endl;
            }
            else{
                cout<<d1[x]+d[y]<<endl;
            }
        }
        for(int i=0;i<=n;i++){
            g[i].clear();
            g1[i].clear();
            d[i]=INF;
            d1[i]=INF;
        }
    }
    return 0;
}


