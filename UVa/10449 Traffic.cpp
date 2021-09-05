///***Bismillahir Rahmanir Rahim***
///***Faizul***
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9+7
struct edge
{
    ll U;ll V;ll W;
    edge(ll a,ll b,ll c)
    {
        U=a;
        V=b; W=c;
    }
};

vector <edge> graph;

ll busyness[5000];

ll dist[5000];

ll node,E;

void bellmanford(ll source)
{
    for(ll i=0;i<5000;i++) dist[i]=INF;

    //for(int i=1;i<=node;i++) cout<<dist[i]<<endl;

    dist[source]=0;

    for(ll i=1;i<10000;i++)
    {
        for(ll j=0;j<E;j++)
        {
            ll u=graph[j].U;
            ll v=graph[j].V;
            ll cost=graph[j].W;

            if(dist[u]+cost <dist[v] && dist[u]!=INF) dist[v]=dist[u]+cost;
        }
    }


}

int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);

    ll test=1;
    ll N,M,Q;

    while(cin>>N)
    {
        for(ll j=1;j<=N;j++)
        {
            cin>>busyness[j];
            //scanf("%lld",&busyness[j]);
        }

        cin>>M;
        //scanf("%lld",&M);

        int u,v;
        for(ll j=1;j<=M;j++)
        {
            cin>>u>>v;
            //scanf("%lld %lld",&u,&v);

            ll w=busyness[v]-busyness[u];
            w=w*w*w;

            graph.push_back(edge(u,v,w));
        }

        node=N; E=M;

        cin>>Q;
        //scanf("%lld",&Q);

        bellmanford(1);

        ll source;

        ll ans[10000];

        //for(int j=1;j<=N;j++) cout<<dist[j]<<endl;

        for(ll j=1;j<=Q;j++)
        {
            cin>>source;
            //scanf("%lld",&source);

            ll X=dist[source];
            //cout<<"query "<<source <<" "<<X<<endl;

            if(X<3 || X==INF) ans[j]=-1;

            else ans[j]=X;
        }

        printf("Set #%lld\n",test);
        test++;

        for(int j=1;j<=Q;j++)
        {
            if(ans[j]==-1) printf("?\n");
            else printf("%lld\n",ans[j]);
        }

        memset(dist,0,sizeof(dist));
        memset(busyness,0,sizeof(busyness));
        graph.clear();

    }

    return 0;

}
