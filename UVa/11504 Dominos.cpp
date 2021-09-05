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
int fx4[]={1,-1,0,0}; int fy4[]={0,0,1,-1};

///******************************************************************************///

vector <int> G[200000];
vector <int> Gr[200000];
vector <int> topsort;

int Mark[200000],visited[200000];

void DFS(int U)
{
    Mark[U]=1;

    for(int i=0;i<G[U].size();i++)
    {
        int V=G[U][i];
        if(Mark[V]==0)
        {
            Mark[V]=1;
            DFS(V);
        }
    }
    topsort.pb(U);
}

void DFS2(int U)
{
    visited[U]=1;

    for(int i=0;i<Gr[U].size();i++)
    {
        int V=Gr[U][i];
        if(visited[V]==0)
        {
            visited[V]=1;
            DFS2(V);
        }
    }
}

int SCC(int N)
{
    for(int i=1;i<=N;i++)
    {
        if(Mark[i]==0)
        {
            Mark[i]=1;
            DFS(i);
        }
    }

    int C=0;

    for(int i=0;i<topsort.size();i++)
    {
        int U=topsort[i];
        if(visited[U]==0)
        {
            visited[U]=1;
            C++;
            DFS2(U);
        }
    }

    return C;

}

int main()
{
    FastIO();

    int T;

    cin>>T;

    for(int x=1;x<=T;x++)
    {
        int N,M;
        cin>>N>>M;

        for(int i=1;i<=M;i++)
        {
            int x,y;
            cin>>x>>y;
            G[x].pb(y);
            Gr[y].pb(x);
        }

        int ans=SCC(N);
        cout<<ans<<endl;

        memset(Mark,0,sizeof(Mark));
        memset(visited,0,sizeof(visited));

        for(int i=1;i<=N;i++) G[i].clear();
        for(int i=1;i<=N;i++) Gr[i].clear();


    }

    return 0;
}
