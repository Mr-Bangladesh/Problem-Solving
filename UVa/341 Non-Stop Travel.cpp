#include <bits/stdc++.h>
using namespace std;
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
vector <edge> graph[100000];

int dist[100000];

int path[10000];

void dijkstra(int source)
{
    for(int i=0;i<100000;i++) dist[i]=INT_MAX;

    queue <int> Q;

    dist[source]=0;

    Q.push(source);

    while(!Q.empty())
    {
        int parent=Q.front();

        Q.pop();

        for(int i=0;i<graph[parent].size();i++)
        {
            int child=graph[parent][i].V;

            if(dist[parent]+graph[parent][i].W < dist[child])
            {
                dist[child]=(dist[parent] + graph[parent][i].W);
                Q.push(child);
                path[child]=parent;
            }
        }
    }

}
void printPath(int s, int t)
{
    if(s==t){printf("%d",t); return;}
    printPath(path[s],t);
    printf(" %d",s);
}
int main()
{
    int testcase=1,N,u,v,w;

    //freopen("1.txt","r",stdin);

    while(cin>>N)
    {
        if(N==0) break;
        int E;
        for(int k=1;k<=N;k++)
        {
            scanf("%d",&E);
            for(int i=1;i<=E;i++)
            {
                cin>>u>>w;
                graph[k].push_back(edge(u,w));
                //graph[u].push_back(edge(k,w));
            }
        }

        int source,des;
        scanf("%d %d",&source,&des);
        dijkstra(source);
        //cout<<dist[des]<<endl;
        printf("Case %d: Path = ",testcase);
        printPath(des,source);
        printf("; %d second delay\n",dist[des]);

        memset(path,0,sizeof(path));
        for(int i=0;i<=N;i++) graph[i].clear();
        testcase++;
    }
}
