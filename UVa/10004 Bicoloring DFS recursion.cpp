#include <bits/stdc++.h>
using namespace std;

vector <int> graph[1000];
int visited[1000];

#define RED 5
#define GREEN 10

bool DFS(int source)
{

    if(visited[source]==0)
        visited[source]=RED;

    int u=source;

    //cout<<u<<" color source "<<bicoloring[u]<<endl;

    bool check=true;

    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];

        if(visited[v]==0 && visited[u]==RED)
        {
            visited[v]=GREEN;

            DFS(v);
        }
        else if(visited[v]==0 && visited[u]==GREEN)
        {
            visited[v]=RED;
            DFS(v);
        }
        else if(visited[v]!=0 && visited[u]==visited[v])
            check=false;
    }

    return check;

}

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    int node,edge,x,y;
    while(cin>>node>>edge){

            if(node==0)
                break;

    for(int i=0;i<edge;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if(DFS(0)==true)
    {
        cout<<"BICOLORABLE."<<endl;
    }
    else
        cout<<"NOT BICOLORABLE."<<endl;

        for(int i=0;i<node;i++)
            graph[i].clear();

        memset(visited,0,sizeof(visited));
        //memset(bicoloring,0,sizeof(bicoloring));

    }
}
