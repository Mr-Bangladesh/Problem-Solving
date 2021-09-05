#include <bits/stdc++.h>
using namespace std;
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

#define MAX INT_MAX

struct edge
{
    int V;
    int W;
    edge(int a,int b)
    {
        V=a;
        W=b;
    }
};

vector <edge> graph[50005];

struct node
{
    int At;
    int Cost;
    node(int a,int b)
    {
        At=a;
        Cost=b;
    }
};

bool operator<(node A,node B)
{
    return A.Cost>B.Cost;
}

int dist[50005];

int dijkstra(int source)
{
    //for(int i=0;i<1000;i++) dist[i]=INT_MAX;

    dist[source]=0;

    priority_queue <node> PQ;
    PQ.push(node(source,0));

    int max_dist=0;

    while(!PQ.empty())
    {
        node parent=PQ.top();

        PQ.pop();

        for(int i=0;i<graph[parent.At].size();i++)
        {
            edge child=graph[parent.At][i];

            if(parent.Cost + child.W < dist[child.V])
            {
                dist[child.V]=parent.Cost + child.W;

                PQ.push(node(child.V,dist[child.V]));
                //cout<<"visited "<<child.V<<endl;

            }

        }

    }

}

int main()
{
    //FastIO();

    int testcase;

    cin>>testcase;

    for(int x=1;x<=testcase;x++)
    {
        for(int i=0;i<50005;i++)
            dist[i]=MAX;

        int M,N,S,T;

        cin>>N>>M>>S>>T;

        int u,v,w;

        for(int i=0;i<M;i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back(edge(v,w));
            graph[v].push_back(edge(u,w));
        }
        dijkstra(S);
        int ans=dist[T];

        if(ans==MAX) cout<<"Case #"<<x<<": unreachable"<<endl;
        else cout<<"Case #"<<x<<": "<<ans<<endl;

        for(int i=0;i<N;i++) graph[i].clear();
    }
    return 0;
}


