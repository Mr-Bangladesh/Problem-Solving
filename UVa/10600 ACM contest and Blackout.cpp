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
    int U,V,W;
    edge(int a,int b,int c)
    {
        U=a; V=b; W=c;
    }
};

vector <edge> E;

bool faizul(edge a,edge b)
{
    return a.W<b.W;
}

int Parent[200005];

void INIT(int N)
{
    for(int i=1;i<=N;i++) Parent[i]=i;
}

int Find(int r)
{
    if(Parent[r]==r) return r;
    else return Parent[r]=Find(Parent[r]);
}

vector <edge> mst;

int Kruskal(int M)
{
    sort(E.begin(),E.end(),faizul);

    int ans=0;

    for(int i=0;i<M;i++)
    {
        int X=E[i].U; int Y=E[i].V; int Cost=E[i].W;

        int PX=Find(X); int PY=Find(Y);

        if(PX!=PY)
        {
            ans+=Cost;
            Parent[PX]=PY;
            mst.pb(edge(X,Y,Cost));
        }
    }
    return ans;
}

int Comp;

int Kruskal2(int M,int X1,int Y1)
{
    int ans=0;

    for(int i=0;i<M;i++)
    {
        int X=E[i].U; int Y=E[i].V; int Cost=E[i].W;

        if(X==X1 && Y==Y1) continue;

        int PX=Find(X); int PY=Find(Y);

        if(PX!=PY)
        {
            Parent[PX]=PY;
            ans+=Cost;
            Comp--;
        }
    }
    return ans;
}

int main()
{
    //freopen("1.txt","r",stdin);

    int N,M,X,Y,W,T;

    cin>>T;

    for(int C=1;C<=T;C++)
    {
        cin>>N>>M;

        INIT(N);

        for(int i=0;i<M;i++)
        {
            cin>>X>>Y>>W;
            E.pb(edge(X,Y,W));
        }

        int ans1=Kruskal(M);

        int ans2=INT_MAX;

        Comp=N;

        for(int i=0;i<mst.size();i++)
        {
            int X=mst[i].U; int Y=mst[i].V; int Cost=mst[i].W;
            INIT(N);
            int MIN=Kruskal2(M,X,Y);
            if(Comp==1)
            {
                ans2=min(ans2,MIN);
            }
            Comp=N;
        }

        cout<<ans1<<" "<<ans2<<endl;

        mst.clear(); E.clear();

        memset(Parent,0,sizeof(Parent));
    }

    return 0;
}
