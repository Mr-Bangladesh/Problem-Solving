#include <bits/stdc++.h>
using namespace std;

int fx[]={-1,-2,-1,-2,1,2,1,2};
int fy[]={-2,-1,2,1,-2,-1,2,1};


int BFS(int s1,int s2,int d1,int d2)
{
    bool visited[100][100];
    queue < pair<int,int> > Q;
    pair<int,int> P;
    int level[100][100];

    memset(level,0,sizeof(level));
    memset(visited,0,sizeof(visited));

    visited[s1][s2]=1;
    Q.push(make_pair(s1,s2));

    level[s1][s2]=0;

    while(!Q.empty())
    {
        P=Q.front();
        int u1=P.first;
        int u2=P.second;

        Q.pop();

        for(int i=0;i<8;i++)
        {
            int v1=u1+fx[i];
            int v2=u2+fy[i];
            if(v1>=1 && v1<=8 && v2>=1 && v2<=8 && visited[v1][v2]==0)
            {
                visited[v1][v2]=1;
                Q.push(make_pair(v1,v2));
                level[v1][v2]=level[u1][u2]+1;
            }
            if(visited[d1][d2]==1)
                return level[v1][v2];
        }
    }
}


int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    char a,b;
    int m,n;
    while(cin>>a>>m>>b>>n)
    {
        int x=a-96;
        int y=b-96;

        if(x==y && m==n){
            printf("To get from %c%d to %c%d takes %d knight moves.\n",a,n,b,n,0);
        }
        else{
        int L=BFS(x,m,y,n);

        printf("To get from %c%d to %c%d takes %d knight moves.\n",a,m,b,n,L);
        }
    }
    return 0;
}
