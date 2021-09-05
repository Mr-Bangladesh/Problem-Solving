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
int fx4[]= {1,-1,0,0};
int fy4[]= {0,0,1,-1};


///***Faizul***CSE**4th batch**BU

int graph[1000][1000];
int visited[1000][1000];
int level[1000][1000];

int BFS(int s1,int s2,int M)
{
    visited[s1][s2]=1;

    level[s1][s2]=0;

    queue< pair<int,int> > Q;

    Q.push(mp(s1,s2));

    while(!Q.empty())
    {
        int u1=Q.front().first;
        int u2=Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int v1=u1+fx4[i];
            int v2=u2+fy4[i];
            if(v1>=0 && v2>=0 && v1<M && v2<M)
            {
                if(visited[v1][v2]==0)
                {
                    visited[v1][v2]=1;

                    Q.push(mp(v1,v2));

                    level[v1][v2]=level[u1][u2]+1;

                    if(graph[v1][v2]==3)
                    {
                        //graph[v1][v2]=4;
                        return level[v1][v2];
                    }
                }
            }
        }
    }
    return 0;

}
int main()
{
    FastIO();

    int M;

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    while(cin>>M)
    {
        int row[1000]= {0};
        int column[1000]= {0};

        string S[1000];

        int k=0;

        for(int i=0; i<M; i++)
        {
            cin>>S[i];
            for(int j=0; j<M; j++)
            {
                if(S[i][j]=='1')
                {
                    graph[i][j]=1;
                    row[k]=i;
                    column[k]=j;
                    k++;
                }

                else if(S[i][j]=='2') graph[i][j]=2;

                else if(S[i][j]=='3') graph[i][j]=3;
            }
        }

        int MAX=0;

        for(int i=0; i<k; i++)
        {
            int X=BFS(row[i],column[i],M);

            memset(visited,0,sizeof(visited));
            memset(level,0,sizeof(level));
            //cout<<X<<endl;
            if(X>MAX) MAX=X;
        }

        cout<<MAX<<endl;

        memset(graph,0,sizeof(graph));

    }



    return 0;
}
