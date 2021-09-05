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

int visited[200000];

vector <int> graph[200000];

int D[200000],F[200000];

vector <int> sorted;

void DFS(int U)
{
    for(int i=0;i<graph[U].size();i++)
    {
        int V=graph[U][i];

        if(visited[V]==0)
        {
            visited[V]=1;
            DFS(V);
        }
    }

    sorted.pb(U);

}

int main()
{
    FastIO();

    int N,M;

    while(cin>>N>>M)
    {
        if(N==0 && M==0) break;

        int X,Y;

        for(int i=1;i<=M;i++)
        {
            cin>>X>>Y;
            graph[X].pb(Y);
        }

        for(int i=1;i<=N;i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                DFS(i);
            }
        }

        reverse(sorted.begin(),sorted.end());

        for(int i=0;i<sorted.size();i++) cout<<sorted[i]<<" "; cout<<endl;

        sorted.clear();
        memset(visited,0,sizeof(visited));

        for(int i=1;i<=N;i++) graph[i].clear();

    }


    return 0;
}
