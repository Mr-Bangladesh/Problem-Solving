#include <bits/stdc++.h>
using namespace std;

vector <int> graph[10000];

int Boom_Day[10000];

void BFS(int source)
{
    int visited[10000]={0};
    queue <int> Q;
    Q.push(source);
    visited[source]=1;

    int level[10000]={0};
    level[source]=0;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        int Count=0;
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(visited[v]==0)
            {
                Q.push(v);
                visited[v]=1;
                level[v]=level[u]+1;
                Boom_Day[level[v]]++;
                Count++;
            }
        }
    }

}

int main()
{
    int people,edge,query;
    cin>>people;
    int x;
    for(int i=0;i<people;i++)
    {
        cin>>edge;
        for(int j=0;j<edge;j++)
        {
            cin>>x;
            graph[i].push_back(x);
        }
    }

    cin>>query;
    int source;
    //BFS(5);

    for(int i=0;i<query;i++)
    {
        cin>>source;
        BFS(source);
        int MAX=0;
        int index=0;
        for(int i=0;i<people;i++)
        {
            if(Boom_Day[i]>MAX)
            {
                MAX=Boom_Day[i];
                index=i;
            }
        }
        if(MAX==0) {cout<<0<<endl; continue;}
        cout<<MAX<<" "<<index<<endl;
        memset(Boom_Day,0,sizeof(Boom_Day));

    }
    for(int i=0;i<people;i++) graph[i].clear();

    //for(int i=0;i<people;i++) cout<<Boom_Day[i]<<endl;



}
