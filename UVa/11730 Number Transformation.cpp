#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
vector <int> graph[MAX];
int prime[MAX];

int len;

void sieve()
{
    int i,j;
    int A[MAX];
    for(i=2;i<MAX;i++)
        A[i]=-1;
    for(i=2;i<MAX;i++)
    {
        if(A[i]==-1)
        {
            for(j=2;i*j<MAX;j++)
                A[i*j]=0;
        }
    }
    j=1;
    for(i=2;i<MAX;i++)
    {
        if(A[i]==-1)
        {
            prime[j]=i;
            j++;
        }
    }
    len=j;
}

void pf()
{
    for(int i=1;i<=MAX;i++)
    {
        for(int j=1;j<len;j++)
        {
            if(i/prime[j]==0)
                break;

            if(i%prime[j]==0 && i!=prime[j])
            {
                if(prime[j]+i<=MAX){
                graph[i].push_back(prime[j]+i);
                //graph[(prime[j]+i)].push_back(i);
                }
            }
        }
    }
}

int BFS(int source,int destination)
{
    int visited[MAX];
    int level[MAX];
    queue <int> Q;

    memset(visited,0,sizeof(visited));
    visited[source]=1;
    level[source]=0;
    Q.push(source);

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

                if(v==destination)
                    return level[v];

                else if(v>destination){
                   break;
                }
            }
        }
    }
        return -1;
}

int main()
{
    sieve();
    pf();

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int T,s,t;
    int i=1;
    while(cin>>s>>t)
    {
        if(s==0 && t==0)
            break;

        if(s==t){
            printf("Case %d: %d\n",i++,0);
            continue;
        }
        int result=BFS(s,t);
        printf("Case %d: %d\n",i++,result);
    }
    return 0;
}
