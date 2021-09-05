///***Bismillahir Rahmanir Rahim***
///***Md Faizul Haque***///
///***University of Barisal***///

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <sstream>
#include<fstream>
#include <iostream>
#include <string>
#include <memory.h>
#include <set>
#include <time.h>
#include <assert.h>
#include <stack>
#include <sstream>
#include <algorithm>

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

int fx8[]={-1,-2,-1,-2,1,2,1,2}; int fy8[]={-2,-1,2,1,-2,-1,2,1};

int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,-1,1,-1,1};

///******************************************************************************///

char S[101][101];

int level[101][101];

void BFS(int S1,int S2,int N,int M)
{
    int visited[101][101]; memset(visited,0,sizeof(visited));

    queue< pair<int,int> > Q; Q.push(mp(S1,S2));

    level[S1][S2]=0;
    visited[S1][S2]=1;

    while(!Q.empty())
    {
        int U1=Q.front().first; int U2=Q.front().second; Q.pop();

        for(int i=0;i<8;i++)
        {
            int V1=U1+fx[i];
            int V2=U2+fy[i];

            if(V1>=0 && V2>=0 && V1<N && V2<M && visited[V1][V2]==0 && S[V1][V2]!='Z')
            {
                visited[V1][V2]=1;
                Q.push(mp(V1,V2));
                level[V1][V2]=level[U1][U2]+1;
            }

        }
    }

}

int main()
{
    FastIO();

    //freopen("input.txt","r",stdin);

    int T;

    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;

        int S1,S2,D1,D2;

        vector < pair<int,int> > V;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cin>>S[i][j];
                if(S[i][j]=='A'){ S1=i; S2=j;}
                if(S[i][j]=='B'){ D1=i; D2=j;}

                if(S[i][j]=='Z') V.pb(mp(i,j));
            }
        }

        for(int i=0;i<V.size();i++)
        {
            int x=V[i].first; int y=V[i].second;

            //cout<<x<<" "<<y<<endl;

            for(int i=0;i<8;i++)
            {
                int x1=x+fx8[i]; int y1=y+fy8[i];


                if(x1>=0 && y1>=0 && x1<N && y1<M && S[x1][y1]!='A' && S[x1][y1]!='B') S[x1][y1]='Z';

            }

        }

        BFS(S1,S2,N,M);

        if(level[D1][D2]==0) cout<<"King Peter, you can't go now!"<<endl;
        else cout<<"Minimal possible length of a trip is "<<level[D1][D2]<<endl;


        memset(level,0,sizeof(level));

    }

    return 0;
}
