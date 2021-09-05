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

int add(string A,string B)
{
    int len1=A.length(); int len2=B.length();

    if(len1!=len2) return 0;

    int Count=0;

    for(int i=0;i<len1;i++)
    {
        if(A[i]!=B[i]) Count++;
    }

    if(Count==1) return 1;
    else return 0;
}

bool BFS(string S,string D)
{
    map<string,int> visited;

    queue<string> Q; bool check=false;

    visited[S]=1;

    Q.push(S);

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
                path[V]=U; //cout<<"visited "<<V<<endl;
            }
            if(visited[D]==1) check=true;
        }
    }
    return check;
}

void printpath(string S,string D)
{
    if(S==D)
    {
        cout<<S<<endl; return;
    }

    printpath(path[S],D);

    cout<<S<<endl;
}

int main()
{
    FastIO();

    //freopen("1.txt","r",stdin);

    string word[200000];

    int i=0;

    while(getline(cin,word[i]))
    {
        if(word[i][0]=='\0') break;
        i++;
    }

    for(int j=0;j<i;j++)
    {
        for(int k=j+1;k<i;k++)
        {
            if(add(word[j],word[k])==1)
            {
                //cout<<word[j]<<" "<<word[k]<<endl;
                graph[word[j]].pb(word[k]);
                graph[word[k]].pb(word[j]);
            }
        }
    }

    string X,Y;

    while(cin>>X>>Y)
    {
        bool check=BFS(X,Y);

        if(check==false)
        {
            cout<<"No solution."<<endl; continue;
        }
        printpath(Y,X);
        cout<<endl;
        path.clear();
    }

    return 0;
}
