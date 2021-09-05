///***Bismillahir Rahmanir Rahim***

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
///cin.ignore();
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}
ll max(ll a,ll b)
{
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a<b) return a;
    else return b;
}
ll pow(ll B,ll P)
{
    ll S=1;
    for(ll i=1; i<=P; i++) S=S*B;
    return S;
}


///***Faizul***CSE**4th batch**BU

int fx[]= {1,-1,0,0,0,0};
int fy[]= {0,0,1,-1,0,0};
int fz[]= {0,0,0,0,1,-1};

struct nodes
{
    int a;
    int b;
    int c;
    nodes(int x,int y,int z)
    {
        a=x;
        b=y;
        c=z;
    }

};

int dist[35][35][35];

int graph[35][35][35];

void BFS(int s1,int s2,int s3,int L,int R,int C)
{
    int visited[35][35][35];
    memset(visited,0,sizeof(visited));

    queue<nodes> Q;
    Q.push(nodes(s1,s2,s3));

    while(!Q.empty())
    {
        nodes u=Q.front();
        Q.pop();
        int u1=u.a;
        int u2=u.b;
        int u3=u.c;


        for(int j=0; j<6; j++)
        {
            int v1=u1+fz[j];
            int v2=u2+fx[j];
            int v3=u3+fy[j];

            if(visited[v1][v2][v3]==0 && v1>=0 && v2>=0 && v3>=0 && v1<L && v2<R && v3<C && graph[v1][v2][v3]!=2)
            {
                visited[v1][v2][v3]=1;
                //cout<<"visited "<<v1<<v2<<v3<<endl;
                Q.push(nodes(v1,v2,v3));
                dist[v1][v2][v3]=dist[u1][u2][u3]+1;
            }
        }
    }
}


int main()
{
    FastIO();

    //freopen("1.txt","r",stdin);

    int L,R,C;

    while(cin>>L>>R>>C)
    {
        if(L==0 && R==0 && C==0) break;

        memset(dist,0,sizeof(dist));
        memset(graph,0,sizeof(graph));

        string S[35][35];

        int s1,s2,s3,d1,d2,d3;

        for(int i=0; i<L; i++)
        {
            for(int j=0; j<R; j++)
            {
                cin>>S[i][j];
                for(int k=0; k<C; k++)
                {
                    if(S[i][j][k]=='.') graph[i][j][k]=1;
                    else if(S[i][j][k]=='#') graph[i][j][k]=2;
                    else if(S[i][j][k]=='S')
                    {
                        s1=i;
                        s2=j;
                        s3=k;
                    }
                    else if(S[i][j][k]=='E')
                    {
                        d1=i;
                        d2=j;
                        d3=k;
                    }
                }

            }
        }

        BFS(s1,s2,s3,L,R,C);
        int ans=dist[d1][d2][d3];


            if(ans>0) printf("Escaped in %d minute(s).\n",ans);

        else printf("Trapped!\n");
    }

    return 0;
}
