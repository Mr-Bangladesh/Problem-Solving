
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

map<string, vector<string> > graph;

//map<string,int> forbidden;

map<string,int> dist;

map<string,int> visited;

int BFS(string source,string des)
{
    visited[source]=1;
    dist[source]=0;
    queue<string> Q;

    Q.push(source);

    while(!Q.empty())
    {
        string u=Q.front(); Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            string v=graph[u][i];

            //if(forbidden[v]==true) continue;

            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v); //cout<<"visited "<<v<<endl;
                dist[v]=dist[u]+1;
                if(visited[des]==1) return dist[des];
            }

        }
    }
    return -1;
}

void func()
{
    int N=9;

    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            for(int k=0;k<=N;k++)
            {
                for(int l=0;l<=N;l++)
                {
                    //cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                    string S=""; S+=(i+48); S+=(j+48); S+=(k+48); S+=(l+48);

                    visited[S]=0;

                    string S_copy=S;

                    for(int m=0;m<4;m++)
                    {
                        string S1,S2;

                        int x1=S_copy[m]-48;

                        int a=x1+1; if(a==10) a=0;
                        int b=x1-1; if(b==-1) b=9;

                        S_copy[m]=(a+48);
                        S1=S_copy;
                        S_copy[m]=(b+48);
                        S2=S_copy;
                        S_copy[m]=(x1+48);

                        graph[S].pb(S1);
                        graph[S].pb(S2);

                    }
                }
            }
        }
    }

}


int main()
{
    FastIO();

    func();

    //for(int i=0;i<graph["9999"].size();i++) cout<<graph["9999"][i]<<" ";

    int T;


    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    cin>>T;

    while(T--)
    {
        int a,b,c,d;

        string source,des;

        cin>>a>>b>>c>>d;
        source+=(a+48); source+=(b+48); source+=(c+48); source+=(d+48);
        cin>>a>>b>>c>>d;
        des+=(a+48); des+=(b+48); des+=(c+48); des+=(d+48);

        int Q;

        cin>>Q;

        for(int i=0;i<Q;i++)
        {
            cin>>a>>b>>c>>d;

            string fo;

            fo+=(a+48); fo+=(b+48); fo+=(c+48); fo+=(d+48);
            //forbidden[fo]=1;
            //cout<<"nised "<<forbidden[fo]<<" "<<fo<<endl;
            visited[fo]=1;
        }
        int ans=BFS(source,des);
        cout<<ans<<endl;

        visited.clear();
        dist.clear();
        //forbidden.clear();

    }


    return 0;
}
