#include <bits/stdc++.h>

using namespace std;

#define RED 1

#define GREEN 2

vector <int> graph[1000];

bool BFS(int source)
{
    bool visited[1000]={0};

    bool check;

    int bicoloring[1000];

    memset(bicoloring,0,sizeof(bicoloring));

    visited[source]=true;

    queue<int> Q;

    Q.push(source);

    bicoloring[source]=RED;

    check=true;

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
            }
            if(bicoloring[v]!=0 && bicoloring[u]==bicoloring[v])
            {
                check=false;
            }
            if(bicoloring[u]==RED && bicoloring[v]==0)
                bicoloring[v]=GREEN;

            else if(bicoloring[u]==GREEN && bicoloring[v]==0)
                bicoloring[v]=RED;
        }
    }

    return check;
}

int main()
{

        //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int n,l,x,y;
    while(cin>>n>>l)
    {
        if(n==0)
            break;
        for(int i=0;i<l;i++)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
            if(BFS(0)==true)
            {
                cout<<"BICOLORABLE."<<endl;
            }
            else
                cout<<"NOT BICOLORABLE."<<endl;

        for(int i=0;i<n;i++)
        graph[i].clear();
    }



    return 0;

}
