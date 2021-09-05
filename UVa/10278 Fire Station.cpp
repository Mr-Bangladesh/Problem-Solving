///ekta node theke dijkstra calale er theke sob ceye durer node nebo.
///sob gulo theke caliye jetay min pabo seta ans.


#include <bits/stdc++.h>
using namespace std;
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

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

vector <edge> graph[10000];

int dist[1000];

int exist[10000];

set <int> node;
set <int> :: iterator it;

int dijkstra(int source)
{
    for(int i=0;i<1000;i++) dist[i]=INT_MAX;

    queue<int> Q;
    dist[source]=0;
    Q.push(source);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].V;

            if(dist[u]+graph[u][i].W <dist[v])
            {
                dist[v]=dist[u]+graph[u][i].W;

                if(exist[v]==1) dist[v]=0;

                Q.push(v);
                //cout<<"visited "<<v<<" dist "<<dist[v]<<endl;
            }
        }
    }
    int MAX=0;
    for(it=node.begin();it!=node.end();it++)
    {
        if(dist[*it]>MAX) MAX=dist[*it];
    }
    return MAX;

}
int main()
{
    FastIO();

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int T;
    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int F,I;
        cin>>F>>I;

        int stations;

        for(int j=1;j<=F;j++) {cin>>stations; exist[stations]=1;}

        int u,v,w;
        cin.ignore();

        string input;

        while(getline(cin,input)&& input!="")
        {
            //if(input=="" "") break;

            stringstream SS(input);

            SS>>u>>v>>w;
            //cout<<u<<v<<w<<endl;

            node.insert(u);
            node.insert(v);
            graph[u].push_back(edge(v,w));
            graph[v].push_back(edge(u,w));
        }


        ///ekhon amra khuje ber korbo kothay staion bosale oi node theke kon node er distance max.

        int MIN=INT_MAX;
        int N=0;

        for(int j=1;j<=I;j++)
        {
            //if(exist[j]==0)
            //{
                int ans=dijkstra(j); ///sob node e fire station bosiye check kortesi je er theke sob ceye
                //cout<<ans<<endl;  ///dure kon node ta ase. je node e fire station bosiye er theke
                if(ans<MIN)         /// sob ceye durer node er dist min pabo setai ans.
                {
                    MIN=ans;
                    N=j;
                }
            //}
        }

        if(N==0) N=1;

        cout<<N<<endl;
        if(i<T) cout<<endl;


        memset(exist,0,sizeof(exist));
        for(it=node.begin();it!=node.end();it++) graph[*it].clear();
        node.clear();

    }
    return 0;

}
