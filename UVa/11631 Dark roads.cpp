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
    ll U,V,W;
    edge(ll a,ll b,ll c)
    {
        U=a; V=b; W=c;
    }
};

vector <edge> E;

bool faizul(edge a,edge b)
{
    return a.W<b.W;
}

ll Parent[200005];

int Find(int r)
{
    if(Parent[r]==r) return r;
    else return Parent[r]=Find(Parent[r]);
}

ll Kruskal(int M)
{
    sort(E.begin(),E.end(),faizul);

    ll ans=0;

    for(int i=0;i<M;i++)
    {
        ll X=E[i].U; ll Y=E[i].V; ll Cost=E[i].W;

        ll PX=Find(X); ll PY=Find(Y);

        if(PX!=PY)
        {
            Parent[PX]=PY;
            ans+=Cost;
        }
    }
    return ans;
}


int main()
{
    //freopen("1.txt","r",stdin);

    ll N,M,X,Y,W;

    while(scanf("%lld %lld",&N,&M))
    {
        if(N==0 && M==0) break;

        for(ll i=0;i<N;i++) Parent[i]=i;

        ll total=0;

        for(int i=1;i<=M;i++)
        {
            //cin>>X>>Y>>W;
            scanf("%lld %lld %lld",&X,&Y,&W);
            total+=W;
            E.pb(edge(X,Y,W));
        }

        ll ans=total-Kruskal(M);

        //cout<<ans<<endl;
        printf("%lld\n",ans);

        E.clear();
        memset(Parent,0,sizeof(Parent));

    }


    return 0;
}
