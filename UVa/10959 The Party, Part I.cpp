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

vector <int> G[20000];

int Depth[20000];

void BFS(int S)
{
    int Mark[20000]={0};

    Mark[S]=1;

    Depth[S]=0;

    queue<int> Q; Q.push(S);

    while(!Q.empty())
    {
        int U=Q.front(); Q.pop();

        for(int i=0;i<G[U].size();i++)
        {
            int V=G[U][i];
            if(Mark[V]==0)
            {
                Mark[V]=1;
                Q.push(V);
                Depth[V]=Depth[U]+1;
            }
        }
    }
}

int main()
{

    //freopen("input.txt","r",stdin);
    FastIO();


    int T;

    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;

        for(int i=0;i<M;i++)
        {
            int X,Y;
            cin>>X>>Y;
            G[X].pb(Y);
            G[Y].pb(X);
        }

        BFS(0);

        for(int i=1;i<N;i++)
        {
            cout<<Depth[i]<<endl;
        }

        if(T) cout<<endl;

        memset(Depth,0,sizeof(Depth));
        for(int i=0;i<=N;i++) G[i].clear();
    }

    return 0;
}
