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


map<string,vector <string> > graph;
map<string,int> visited;
map<string,int> IN;
vector<string> nodes;

vector <string> sorted;

void topsort()
{
    set<string> Q;

    for(int i=0;i<nodes.size();i++)
    {
        if(IN[nodes[i]]==0) Q.insert(nodes[i]);
    }

    while(!Q.empty())
    {
        auto it=Q.begin();
        string U=*it; Q.erase(*it);

        sorted.pb(U);

        for(int i=0;i<graph[U].size();i++)
        {
            string V=graph[U][i];

            if(IN[V]>0) IN[V]--;
            if(IN[V]==0) Q.insert(V);
        }
    }
}

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    int N,M;

    int C=1;

    while(cin>>N)
    {
        string S;

        for(int i=1;i<=N;i++)
        {
            cin>>S;
            visited[S]=0;
            nodes.pb(S);
        }

        cin>>M;

        string X,Y;

        for(int i=1;i<=M;i++)
        {
            cin>>X>>Y;
            graph[X].pb(Y);
            IN[Y]++;
        }

        topsort();

        printf("Case #%d: Dilbert should drink beverages in this order: ",C);

        int loop=sorted.size();

        for(int i=0;i<loop;i++)
        {
            cout<<sorted[i];
            if(i<loop-1) cout<<" ";
        }

        cout<<"."<<endl;

        cout<<endl;

        C++;

        sorted.clear(); graph.clear(); visited.clear(); nodes.clear(); IN.clear();

    }

    return 0;
}
