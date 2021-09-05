///***Bismillahir Rahmanir Rahim***
///***Faizul***CSE**4th batch**BU
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
///cin.ignore();
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll graph[1001][1001];
ll level[1000][1000];
ll visited[1000][1000];

ll fx[]={0,0,1,-1};
ll fy[]={-1,1,0,0};

ll BFS(ll s1,ll s2,ll d1,ll d2,ll R,ll C)
{
    visited[s1][s2]=1;
    level[s1][s2]=0;

    queue< pair<ll,ll> > Q;

    Q.push(make_pair(s1,s2));

    while(!Q.empty())
    {
        ll u1=Q.front().first;
        ll u2=Q.front().second;

        Q.pop();

        for(ll i=0;i<4;i++)
        {
            ll v1=u1+fx[i];
            ll v2=u2+fy[i];

            if(v1>=0 && v2>=0 && v1<R && v2<C && graph[v1][v2]!=-1 && visited[v1][v2]==0)
            {
                visited[v1][v2]=1;
                level[v1][v2]=level[u1][u2]+1;
                Q.push(make_pair(v1,v2)); //cout<<"visited "<<v1<<" "<<v2<<endl;

                if(visited[d1][d2]==1)
                {
                    return level[d1][d2];
                }

            }


        }
    }

    return -1;

}

int main()
{
    FastIO();

    ll R,C;

    while(cin>>R>>C)
    {
        if(R==0 && C==0) break;

        ll bombs;
        cin>>bombs; ll row,column,N;

        for(ll i=1;i<=bombs;i++)
        {
            cin>>row>>N;
            for(ll j=1;j<=N;j++)
            {
                cin>>column;
                graph[row][column]=-1;
            }
        }

        ll s1,s2,d1,d2;

        cin>>s1>>s2;
        cin>>d1>>d2;

        ll result=BFS(s1,s2,d1,d2,R,C);

        memset(visited,0,sizeof(visited));
        memset(level,0,sizeof(level));
        memset(graph,0,sizeof(graph));

        cout<<result<<endl;

    }


    return 0;
}
