///***Bismillahir Rahmanir Rahim***
///***Md Faizul Haque***///
///***University of Barisal***///

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

///******************************************************************************///
map<string,vector <string> > graph;
map<string,string> path;

bool BFS(string S,string D)
{
    map<string,int> visited;
    queue<string>Q;

    visited[S]=1;
    Q.push(S);

    bool check=false;

    while(!Q.empty())
    {
        string U=Q.front(); Q.pop();

        for(int i=0;i<graph[U].size();i++)
        {
            string V=graph[U][i];

            if(visited[V]==0)
            {
                visited[V]=1;
                Q.push(V);
                path[V]=U;
            }
            if(visited[D]==1) check=true;
        }
    }
    return check;
}

vector <string> ans;

void printpath(string S,string D)
{
    if(S==D)
    {
        ans.pb(S);
        return;
    }
    printpath(path[S],D);
    ans.pb(S);
}

int main()
{
    FastIO();

    int N;

    //freopen("1.txt","r",stdin);

    while(cin>>N)
    {
        string U,V;

        for(int i=0;i<N;i++)
        {
            cin>>U>>V;
            graph[U].pb(V);
            graph[V].pb(U);
        }

        string S,D;

        cin>>S>>D;

        bool check=BFS(S,D);
        if(check==false)
        {
            cout<<"No route"<<endl;
            continue;
        }

        printpath(D,S);

        int len=ans.size();

        for(int i=0;i<len-1;i++)
        {
            cout<<ans[i]<<" "<<ans[i+1]<<endl;
        }
        //cout<<ans[len-2]<<" "<<ans[len-1]<<endl;
        cout<<endl;
        graph.clear();
        path.clear();
        ans.clear();
    }

    return 0;
}
