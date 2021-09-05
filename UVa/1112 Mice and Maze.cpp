#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int V; int W;
    edge(int a,int b)
    {
        V=a; W=b;
    }
};

vector <edge> graph[1000];

int dist[1000];

void dijkstra(int source)
{
    for(int i=0;i<1000;i++) dist[i]=INT_MAX;

    dist[source]=0;

    queue<int> Q;
    Q.push(source);

    while(!Q.empty())
    {
        int u=Q.front();

        Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].V;
            int cost=graph[u][i].W;
            if(dist[u]+cost <dist[v])
            {
                dist[v]=dist[u]+cost;
                Q.push(v);
            }
        }
    }
}

int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int T;
    cin>>T;
    int Nodes,Exit,time;
    int M,u,v,w;
    for(int test=1;test<=T;test++)
    {
        cin>>Nodes;
        cin>>Exit;
        cin>>time;

        cin>>M;
        for(int i=1;i<=M;i++)
        {
            cin>>u>>v>>w;
            //graph[u].push_back(edge(v,w));
            graph[v].push_back(edge(u,w));
        }

        dijkstra(Exit);
        int Count=0;

        //for(int i=1;i<=Nodes;i++) cout<<i<<" "<<dist[i]<<endl;

        for(int i=1;i<=Nodes;i++)
        {
            if(dist[i]<=time) Count++;
        }

        cout<<Count<<endl;

        for(int i=0;i<1000;i++) graph[i].clear();
        memset(dist,0,sizeof(dist));

        if(test==T) continue;

        cout<<endl;

    }
    return 0;
}
