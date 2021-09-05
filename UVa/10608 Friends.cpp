#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector <LL> graph[500005];

LL BFS(LL source)
{
    bool visited[500005]={0};

    queue <LL> Q;

    Q.push(source);

    visited[source]=true;

    LL distance=1;

    while(!Q.empty())
    {
        LL u=Q.front();

        Q.pop();

        for(LL i=0;i<graph[u].size();i++)
        {
            LL v=graph[u][i];

            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v);

                distance++;
            }
        }
    }
    return distance;
}


int main()
{
        //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    LL N,M,T;
    LL X,Y;
    cin>>T;
    for(LL x=1;x<=T;x++){

    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        cin>>X>>Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }
    LL MAX=0;
    for(int j=1;j<=N;j++)
    {
        LL S=BFS(j);
        if(S>MAX)
            MAX=S;
    }
    cout<<MAX<<endl;

    for(int i=1;i<=N;i++)
        graph[i].clear();

    }
    return 0;
}
