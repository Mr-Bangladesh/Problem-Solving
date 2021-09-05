/////***Bismillahir Rahmanir Rahim***
//
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define INF 100000000000000000
//#define pb push_back
//#define mp make_pair
/////cin.ignore();
//void FastIO() {ios_base:: sync_with_stdio(false); cin.tie(0); cout.precision(20);}
//ll max(ll a,ll b) {if(a>b) return a; else return b;}
//ll min(ll a,ll b) {if(a<b) return a; else return b;}
//ll pow(ll B,ll P) { ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;}
//ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
//
//
/////***Faizul***CSE**4th batch**BU
//
//struct edge{
//    string U;string V; ll cost;
//    edge(string a,string b,ll c)
//    {
//        U=a; V=b; cost=c;
//    }
//
//};
//
//string source="Calgary" , des="Fredericton";
//
//vector <edge> graph;
//
//ll N; ll E;
//
//map<string,ll> dist;
//
//int ans[10000];
//
//void Bellmanford(ll Q)
//{
//    dist[source]=0;
//
//    int x=0;
//
//    for(int i=0;i<N-1;i++)
//    {
//        for(int j=0;j<E;j++)
//        {
//            string u=graph[j].U;
//            string v=graph[j].V;
//            ll w=graph[j].cost;
//
//            //cout<<u<<" "<<v<<dist[v]<<endl;
//
//            if(dist[u]+w <dist[v])
//            {
//                dist[v]=dist[u]+w;
//                if(v==des)
//                {
//                    cout<<dist[des]<<endl;
//                    ans[x++]=dist[des];
//                }
//            }
//            //dist[v]=dist[u]+w;
//
//        }
//    }
//}
//
//int main()
//{
//    FastIO();
//
//    ll T;
//
//    cin>>T;
//
//    for(ll test=1;test<=T;test++)
//    {
//        cin>>N;
//
//        string nodes[10000];
//
//        for(ll i=1;i<=N;i++)
//        {
//            cin>>nodes[i];
//            dist[nodes[i]]=INF;
//        }
//
//        cin>>E; string u,v; ll w;
//
//        for(ll i=0;i<E;i++)
//        {
//            cin>>u>>v;
//            cin>>w;
//
//            graph.pb(edge(u,v,w));
//        }
//
//        ll Q;
//
//        cin>>Q; ll X;
//
//        for(ll i=0;i<Q;i++)
//        {
//            cin>>X;
//            Bellmanford(X);
//            //cout<<dist[des]<<endl;
//            cout<<ans[X]<<endl;
//        }
//
//        graph.clear(); dist.clear();
//
//    }
//
//    return 0;
//}

///***Bismillahir Rahmanir Rahim***

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
///cin.ignore();
void FastIO() {ios_base:: sync_with_stdio(false); cin.tie(0); cout.precision(20);}
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll pow(ll B,ll P) { ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;}
int fx4[]={1,-1,0,0}; int fy4[]={0,0,1,-1};


///***Faizul***CSE**4th batch**BU

struct edge{
    string V; ll W;
    edge(string a,ll b)
    {
        V=a; W=b;
    }
};

string source="Calgary" , des="Fredericton";

map<string,vector <edge> > graph;

map<string,ll> dist;

ll ans[10000];

void dijkstra()
{
    map<string,ll> level;

    queue<string> Q;

    Q.push(source); dist[source]=0; level[source]=0;

    while(!Q.empty())
    {
        string u=Q.front();
        Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            string v=graph[u][i].V;
            ll Cost=graph[u][i].W;

            if(dist[u]+Cost <dist[v])
            {
                dist[v]=dist[u]+Cost;
                level[v]=level[u]+1;
                Q.push(v);
                //cout<<"visited "<<v<<" "<<dist[v]<<" "<<level[v]<<endl;
                if(v==des) ans[level[v]-1]=dist[v];
            }
        }
    }
}

int main()
{
    FastIO();

    freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    ll T;

    cin>>T;

    for(int test=1;test<=T;test++)
    {
        ll N,M;

        cout<<"Scenario #"<<test<<endl;

        cin>>N;

        string nodes[10000],u,v; ll w;

        for(int i=0;i<N;i++)
        {
            cin>>nodes[i];
            dist[nodes[i]]=INT_MAX;
        }

        cin>>M;

        for(int i=0;i<M;i++)
        {
            cin>>u>>v;

            cin>>w;
            graph[u].pb(edge(v,w));
            graph[v].pb(edge(u,w));
        }

        for(int i=0;i<1000;i++) ans[i]=INT_MAX;

        dijkstra();

        ll Q;

        cin>>Q; int X;

        for(int i=0;i<Q;i++)
        {
            cin>>X;

            if(ans[X]==INT_MAX) cout<<"No satisfactory flights"<<endl;
            else cout<<"Total cost of flight(s) is $"<<ans[X]<<endl;
        }
        if(test!=T) cout<<endl;


        graph.clear();
        dist.clear();
        memset(ans,0,sizeof(ans));

    }

    return 0;
}

