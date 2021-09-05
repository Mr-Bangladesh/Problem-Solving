/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
//ll max(ll a,ll b) {if(a>b) return a; else return b;}
//ll min(ll a,ll b) {if(a<b) return a; else return b;}

vector <int> graph[100004];
vector <int> graph_R[100004];
int visited[100004];
stack<int> topsort;
void DFS(int U)
{
    visited[U]=1;
    for(int i=0;i<graph[U].size();i++){
        int V=graph[U][i];
        if(visited[V]==0){
            visited[V]=1;
            DFS(V);
        }
    }
    topsort.push(U);
}
int visited1[100004];
vector <int> comp[100004];
void DFS2(int U,int mark)
{
    comp[mark].pb(U);
    visited1[U]=1;
    for(int i=0;i<graph_R[U].size();i++){
        int V=graph_R[U][i];
        if(visited1[V]==0){
            visited1[V]=1;
            DFS2(V,mark);
        }
    }
}
int SCC(int N)
{
    for(int i=1;i<=N;i++){
        if(visited[i]==0){
            visited[i]=1;
            DFS(i);
        }
    }
    int mark=0;
    while(!topsort.empty())
    {
        int U=topsort.top();
        topsort.pop();
        if(visited1[U]==0){
            mark++;
            DFS2(U,mark);
        }
    }
    return mark;
}

int main()
{
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int N,M,X,Y;
        scanf("%d %d",&N,&M);
        for(int i=1;i<=M;i++){
            cin>>X>>Y;
            if(X==Y) continue;
            graph[X].pb(Y);
            graph_R[Y].pb(X);
        }
        int C=SCC(N);
        int cnt=0;
        for(int i=1;i<=C;i++)
        {
            if(comp[i].size()==1){
                int x=comp[i][0];
                if(graph[x].size()!=0){
                    //cout<<x<<endl;
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n",cs++,cnt);

        for(int i=1;i<=N;i++){
            graph[i].clear(); graph_R[i].clear();
            visited[i]=visited1[i]=0;
            comp[i].clear();

        }
        while(!topsort.empty()){
            topsort.pop();
        }
    }

    return 0;
}


