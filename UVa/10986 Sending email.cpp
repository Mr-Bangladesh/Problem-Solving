           ///Faizul///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX INT_MAX
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

struct faizul
{
    int first;
    int cost;
    faizul(int a,int b)
    {
        first=a;
        cost=b;
    }
};

vector <faizul> graph[50005];
int dis[50005];

int dijkstra(int source)
{
    queue <int> Q;
    Q.push(source);
    dis[source]=0;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].first;

            if(dis[u]+graph[u][i].cost <dis[v])
            {
                Q.push(v);
                dis[v]=dis[u]+graph[u][i].cost;
            }
        }
    }
}

int main()
{
    FastIO();

    int testcase;
    cin>>testcase;
    for(int x=1;x<=testcase;x++)
    {
        for(int i=0;i<50005;i++)
            dis[i]=MAX;

        int M,N,S,T;
        cin>>N>>M>>S>>T;
        int u,v,w;
        for(int i=0;i<M;i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back(faizul(v,w));
            graph[v].push_back(faizul(u,w));
        }
        dijkstra(S);
        int ans=dis[T];

        if(ans==MAX) cout<<"Case #"<<x<<": unreachable"<<endl;
        else cout<<"Case #"<<x<<": "<<ans<<endl;

        for(int i=0;i<N;i++) graph[i].clear();
    }
    return 0;
}
