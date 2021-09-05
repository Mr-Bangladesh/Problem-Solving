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

struct edge{
    string U,V; int W;
    edge(string a,string b,int c)
    {
        U=a; V=b; W=c;
    }
};

vector <edge> E;

bool faizul(edge a,edge b)
{
    return a.W>b.W;
}

map<string,string> Parent;

string Find(string r)
{
    if(Parent[r]==r) return r;
    else return Parent[r]=Find(Parent[r]);
}

ll Kruskal(int M,string source,string des)
{
    sort(E.begin(),E.end(),faizul);

    int ans=INT_MAX;

    for(int i=0;i<M;i++)
    {
        string X=E[i].U; string Y=E[i].V; int Cost=E[i].W;

        string PX=Find(X); string PY=Find(Y);

        if(PX!=PY)
        {
            Parent[PX]=PY;
            ans=min(ans,Cost);
        }

        PX=Find(source); PY=Find(des);

        if(PX==PY)
        {
            return ans;
        }

    }
}

int main()
{
    //freopen("1.txt","r",stdin);

    int N,M;

    int C=1;

    while(cin>>N>>M)
    {
        if(N==0 && M==0) break;

        string X,Y; int W;

        for(int i=1;i<=M;i++)
        {
            cin>>X>>Y>>W;
            Parent[X]=X; Parent[Y]=Y;
            E.pb(edge(X,Y,W));
        }

        string S,D;

        cin>>S>>D;

        int ans=Kruskal(M,S,D);

        printf("Scenario #%d\n",C);
        printf("%d tons\n\n",ans);

        C++;

        Parent.clear(); E.clear();
    }

    return 0;
}
