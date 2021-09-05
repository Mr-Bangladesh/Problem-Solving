///ekhane bola ase je source theke ekebare past e jaoa jabe kina mane negative cycle find korte hobe
///jodi kono negative cycle pai taholei bolte pari je past e jaoa somovob
///noyto na.

#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int U;int V;int W;
    edge(int a,int b,int c)
    {
        U=a; V=b; W=c;
    }
};
int N,M;
vector<edge> graph;

int dist[1009];

int bellmanford(int source)
{
    for(int i=0;i<1009;i++) dist[i]=INT_MAX;

    dist[source]=0;

    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<M;j++)
        {
            int u=graph[j].U;
            int v=graph[j].V;
            int cost=graph[j].W;

            if(dist[u]+cost <dist[v])
                dist[v]=dist[u]+cost;
        }
    }

    for(int i=0;i<M;i++)
    {
        int u=graph[i].U;
        int v=graph[i].V;
        int cost=graph[i].W;
        if(dist[u]+cost <dist[v])  ///negative cycle pailei 1 return kore disi.
            return 1;
    }

    return 0;

}

int main()
{
    int T;

    scanf("%d",&T);

    for(int Case=1;Case<=T;Case++)
    {
        scanf("%d %d",&N,&M);

        int x,y,t;

        for(int i=1;i<=M;i++)
        {
            scanf("%d %d %d",&x,&y,&t);
            graph.push_back(edge(x,y,t));
        }

        int check = bellmanford(0);

        if(check==1) printf("possible\n");

        else printf("not possible\n");

        graph.clear();

    }

    return 0;

}
