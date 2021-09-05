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

string V[100];

map<string,vector <string> > graph;

map<string,int> visited;
map<string,int> dist;

int BFS(string source,string des)
{
    visited[source]=1;
    dist[source]=0;

    queue<string> Q; Q.push(source);

    while(!Q.empty())
    {
        string u=Q.front(); Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            string v=graph[u][i];

            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v); //cout<<"visited "<<v<<endl;
                dist[v]=dist[u]+100;
                if(visited[des]==1) return dist[des];
            }

        }
    }

    return -1;

}

int main()
{
    FastIO();

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int T;

    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;

    cin>>T;

    for(int test=1;test<=T;test++)
    {
        //printf("DATA SET %d\n\n",test);
        cout<<"DATA SET  "<<test<<endl<<endl;

        int node,edge,query;

        cin>>node>>edge>>query;

        for(int i=0;i<node;i++) cin>>V[i];

        string X,Y;

        for(int i=0;i<edge;i++)
        {
            cin>>X>>Y;
            graph[X].pb(Y);
            graph[Y].pb(X);
        }

        int cost,ans=0;

        int faizul[2000];

        for(int i=0;i<query;i++)
        {
            cin>>cost;
            cin>>X>>Y;

            int C=BFS(X,Y);

            dist.clear();
            visited.clear();

            ans=cost*C;

            faizul[i]=ans;
        }

        for(int i=0;i<query;i++)
        {
            if(faizul[i]<0) cout<<"NO SHIPMENT POSSIBLE"<<endl;
            else cout<<"$"<<faizul[i]<<endl;
        }

        cout<<endl;

        graph.clear();

    }

    cout<<"END OF OUTPUT"<<endl;


    return 0;
}
