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
struct edge{
    ll first,second;
    edge(ll a,ll b){
        first=a;
        second=b;
    }
};
map<ll,vector< pair<ll,ll> > >g2,g1;
map<ll,ll> d1,d2;
bool operator<(edge a,edge b){
    return a.second>b.second;
}

void dijkstra1(ll s){
    priority_queue<edge> pq;
    pq.push(edge(s,0));
    d1[s]=0;
    while(!pq.empty()){
        auto u=pq.top(); pq.pop();
        if(u.second!=d1[u.first]) continue;
        for(auto v:g1[u.first]){
            if(u.second+v.second<d1[v.first]){
                d1[v.first]=u.second+v.second;
                pq.push(edge(v.first,d1[v.first]));
            }
        }
    }
}

void dijkstra2(ll s){
    priority_queue<edge> pq;
    pq.push(edge(s,0));
    d2[s]=0;
    while(!pq.empty()){
        auto u=pq.top(); pq.pop();
        if(u.second!=d2[u.first]) continue;
        for(auto v:g2[u.first]){
            if(u.second+v.second<d2[v.first]){
                d2[v.first]=u.second+v.second;
                pq.push(edge(v.first,d2[v.first]));
            }
        }
    }
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            d1[i]=INF;
            d2[i]=INF;
        }
        for(int i=1;i<=m;i++){
            cin>>x>>y>>w;
            g1[x].pb(mp(y,w));
            g2[y].pb(mp(x,w));
        }
        dijkstra1(1);
        dijkstra2(1);
        ll ans=0;
        for(int i=1;i<=n;i++) ans+=(d1[i]+d2[i]);

        cout<<ans<<endl;

        g1.clear(); g2.clear(); d1.clear(); d2.clear();
    }

    return 0;
}



