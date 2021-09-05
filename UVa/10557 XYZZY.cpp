#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int U;int V;
    edge(int a,int b)
    {
        U=a; V=b;
    }
};
vector<edge> graph;
int cost[10000];

int dist[1000];

int N,M;

int bellmanford(int source)
{
    //cout<<M<<" "<<N<<endl;
    for(int i=0;i<1000;i++) dist[i]=INT_MAX;

    dist[source]=100;

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int u=graph[j].U;
            int v=graph[j].V;
            if(dist[u]+cost[v]<dist[v]){
                dist[v]=dist[u]+cost[v];
                //cout<<"realxed "<<v<<" "<<dist[v]<<endl;
            }
        }
    }

    for(int j=0;j<M;j++)
    {
        int u=graph[j].U;
        int v=graph[j].V;
        if(dist[u]+cost[v]<dist[v])
            {
                //cout<<"Negative cycle found"<<endl;
                break;
            }
    }


}

int main()
{
    while(scanf("%d",&N))
    {
        if(N==-1) break;

        int value,nodes;
        M=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d %d",&value,&nodes);
            cost[i]=value;
            M+=nodes;
            int x;
            for(int j=0;j<nodes;j++)
            {
                scanf("%d",&x);
                graph.push_back(edge(i,x));
            }

        }
        //for(int i=0;i<graph.size();i++) cout<<graph[i].U<<" "<<graph[i].V<<endl;
        bellmanford(1);
    }
}
