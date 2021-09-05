#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 50005
vector <ll> graph[MAX];

ll visited[MAX];
ll Count=1;
void DFS(int source)
{
    //cout<<"source "<<source<<endl;
    if(visited[source]==1)
        return;
    visited[source]=1;
    ll u=source;
    for(ll i=0;i<graph[u].size();i++)
    {
        ll v=graph[u][i];
        if(visited[v]==0)
        {
            Count++;
            //cout<<"visited "<<v<<endl;
            DFS(v);
        }
    }
}

int main()
{
    ll T,N,M,x,y;

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    cin>>T;
    for(ll i=1;i<=T;i++)
    {
        cin>>N>>M;
        set<ll> S;
        set<ll> :: iterator it;
        for(ll j=1;j<=M;j++)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
            S.insert(x);
            S.insert(y);
        }
        ll M=0;

        for(it=S.begin();it!=S.end();it++)
        {
            DFS(*it);
            if(Count>M)
                M=Count;
            Count=1;

        }
        memset(visited,0,sizeof(visited));
        if(M==0)
            cout<<1<<endl;
        else
            cout<<M<<endl;

        memset(graph,0,sizeof(graph));

    }
    return 0;
}
