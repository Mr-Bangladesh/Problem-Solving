#include <bits/stdc++.h>
using namespace std;
#define RED 1
#define GREEN 2

vector <int> graph[100];

bool DFS(int source)
{
    int visited[10000]={0};
    stack <int> S;

    visited[source]=1;
    S.push(source);

    int bicoloring[1000]={0};

    bicoloring[source]=RED;

    bool flag=true;

    while(!S.empty())
    {
        int u=S.top();

        bool check=false;

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                //cout<<"visited "<<v<<endl;
                S.push(v);
                check=true;

                /*if(bicoloring[v]!=0 && bicoloring[v]==bicoloring[u])
                    flag=false;
                if(bicoloring[v]==0 && bicoloring[u]==RED)
                    bicoloring[v]=GREEN;
                else if(bicoloring[v]==0 && bicoloring[u]==GREEN)
                    bicoloring[v]=RED;*/

                break;
            }

            if(check==false && visited[v]!=0)
            {
                visited[v]=2;
                S.pop();
                continue;
            }
            if(bicoloring[v]!=0 && bicoloring[u]==bicoloring[v])
            {
                flag=false;
            }
            if(bicoloring[v]==0 && bicoloring[u]==RED)
            {
                bicoloring[v]=GREEN;
            }
            else if(bicoloring[v]==0 && bicoloring[u]==GREEN)
            {
                bicoloring[v]=RED;
            }

            //cout<<"color "<<v<<" "<<bicoloring[v]<<endl;

        }
    }
    return flag;
}
int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int n,l,x,y;
    while(cin>>n>>l){
            if(n==0)
            break;

    for(int i=1;i<=l;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(DFS(0)==true)
        cout<<"BICOLORABLE"<<endl;
    else
        cout<<"NOT BICOLORABLE"<<endl;

    for(int i=0;i<=n;i++)
        graph[i].clear();

    }

}
