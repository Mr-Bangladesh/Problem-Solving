///***Bismillahir Rahmanir Rahim***

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
///cin.ignore();
void FastIO() {ios_base:: sync_with_stdio(false); cin.tie(0); cout.precision(20);}
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll pow(ll B,ll P) { ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;}
int fx4[]={1,-1,0,0}; int fy4[]={0,0,1,-1};
#define RED 1
#define GREEN 2

///***Faizul***CSE**4th batch**BU

vector <int> graph[1000];
int visited[1000];

int BFS(int source)
{
    if(visited[source]==1) return 0;
    int Mark[1000]={0};

    Mark[source]=RED;

    int Count1=1; int Count2=0;

    visited[source]=1;
    queue<int> Q; Q.push(source);

    while(!Q.empty())
    {
        int u=Q.front(); Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(visited[v]==0)
            {
                if(Mark[u]==RED) { Mark[v]=GREEN; Count2++;}
                else if(Mark[u]==GREEN) { Mark[v]=RED; Count1++;}

                visited[v]=1;
                Q.push(v);
            }

            else if(visited[v]==1)
            {
                if(Mark[u]==Mark[v])
                    return -1;
            }

        }
    }
    Count1=max(Count1,1);
    Count2=max(Count2,1);
    return min(Count1,Count2);
}

int main()
{
    FastIO();

    int T;

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    cin>>T;

    while(T--)
    {
        int N,M;

        cin>>N>>M;

        int u,v;

        for(int i=0;i<M;i++)
        {
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }

        int ans=0; bool check=true;

        for(int i=0;i<N;i++)
        {
            int X=BFS(i);
            if(X==-1)
            {
                check=false; break;
            }
            else ans+=X;
        }
        if(check==false) cout<<"-1"<<endl;
        else cout<<ans<<endl;

        memset(visited,0,sizeof(visited));
        for(int i=0;i<1000;i++) graph[i].clear();
    }

    return 0;
}
