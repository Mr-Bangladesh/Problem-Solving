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


///***Faizul***CSE**4th batch**BU

vector <int> graph[10000];
int path[20000];

void BFS(int source,int des)
{
    //printf("%c\n",source+64);
    int visited[10000]={0}; visited[source]=1;

    queue<int> Q; Q.push(source);

    while(!Q.empty())
    {
        int u=Q.front(); Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(visited[v]==0)
            {
                visited[v]=1; Q.push(v);
                path[v]=u;
            }
        }
    }
}

string ans;

void printpath(int S,int T)
{
    if(S==T)
    {
        ans+=(S+64);
        //printf("%c",S+64);
        return;
    }
    printpath(path[S],T);
    ans+=(S+64);
    //printf("%c",S+64);
}

int main()
{
    FastIO();

    int T;

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    cin>>T;

    for(int x=1;x<=T;x++)
    {
        int M,Q;

        cin>>M>>Q;

        string S1,S2;

        for(int i=1;i<=M;i++)
        {
            cin>>S1>>S2;
            graph[S1[0]-64].pb(S2[0]-64);
            graph[S2[0]-64].pb(S1[0]-64);
        }

        string result[1000];

        for(int i=1;i<=Q;i++)
        {
            cin>>S1>>S2;

            BFS(S1[0]-64,S2[0]-64);
            printpath(S2[0]-64,S1[0]-64);

            result[i]=ans;
            ans="";
        }

        for(int i=1;i<=Q;i++) cout<<result[i]<<endl;

        memset(path,0,sizeof(path));

        for(int i=0;i<1000;i++) graph[i].clear();

        if(x!=T) cout<<endl;
    }

    return 0;
}
