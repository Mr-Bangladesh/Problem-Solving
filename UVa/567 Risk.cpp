#include <bits/stdc++.h>
using namespace std;

vector <int> graph[1000];

int BFS(int source,int destination)
{
    bool visited[1000]={0};

    int level[1000]={0};

    queue <int> Q;

    Q.push(source);

    visited[source]=true;


    level[source]=0;

    while(!Q.empty())
    {
        int u=Q.front();

        Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];

            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v);
                level[v]=level[u]+1;
                //cout<<"Visited "<<v<<endl;
            }
        }
    }
    return level[destination];
}

int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int nodes,X,T=1;

    while(cin>>nodes){
            for(int i=1;i<=nodes;i++)
            {
                cin>>X;
                graph[1].push_back(X);
                graph[X].push_back(1);
            }

    for(int line = 2; line<=19;line++)
    {
        cin>>nodes;

        for(int i=1;i<=nodes;i++)
        {
            cin>>X;
            graph[line].push_back(X);
            graph[X].push_back(line);
        }
    }

    int N;

    cin>>N;

    int source,destination;

    printf("Test Set #%d\n",T++);

    for(int i=1;i<=N;i++)
    {
        cin>>source>>destination;

        printf("%2d to%3d: %d\n",source,destination,BFS(source,destination));
    }
    cout<<endl;
    //memset(level,0,sizeof(level));
    for(int i=0;i<=20;i++)
    {
        graph[i].clear();
    }
    }
    return 0;
}
