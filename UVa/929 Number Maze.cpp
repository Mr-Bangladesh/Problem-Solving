#include <bits/stdc++.h>
using namespace std;
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}
int fx[]={0,0,-1,1};
int fy[]={-1,1,0,0};
int graph[1000][1000];
int dist[1000][1000];
int visited[1000][1000];
struct node
{
    int u;
    int v;
    int w;
    node(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
};

bool operator<(node A,node B)
{
    return A.w>B.w;
}

void dijkstra(int N,int M)
{
    //cout<<"asche"<<endl;
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
            dist[i][j]=INT_MAX;
    }

    visited[0][0]=1;
    dist[0][0]=graph[0][0];
    priority_queue<node> PQ;

    PQ.push(node(0,0,dist[0][0]));

    while(!PQ.empty())
    {
        node parent=PQ.top();
        PQ.pop();
        for(int i=0;i<4;i++)
        {
            int v1=parent.u + fx[i];
            int v2=parent.v + fy[i];
            if(v1>=0 && v2>=0 && v1<N && v2<M && visited[v1][v2]==0)
            {
                if(dist[parent.u][parent.v] + graph[v1][v2] < dist[v1][v2])
                {
                    dist[v1][v2]=dist[parent.u][parent.v] + graph[v1][v2];
                    visited[v1][v2]=1;
                    PQ.push(node(v1,v2,dist[v1][v2]));
                }
            }
        }
    }

}


int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    int N,M;
    cin>>T;
    for(int x=0;x<T;x++)
    {
        cin>>N;
        cin>>M;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cin>>graph[i][j];
            }
        }
        dijkstra(N,M);
        cout<<dist[N-1][M-1]<<endl;
        memset(visited,0,sizeof(visited));
    }
}
