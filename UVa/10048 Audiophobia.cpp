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

ll G[300][300];

void FW(int N)
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(i==j) continue;
                G[i][j]=min(G[i][j],max(G[i][k],G[k][j]));
            }
        }
    }
}

int main()
{

    ll N,M,Q;

    int Case=1;

    while(cin>>N>>M>>Q)
    {
        if(N==0 && M==0 && Q==0) break;

        if(Case>1) cout<<endl;

        int X,Y,W;

        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                G[i][j]=INT_MAX;

                if(i==j) G[i][j]=0;
            }
        }

        for(int i=1;i<=M;i++)
        {
            cin>>X>>Y>>W;
            G[X][Y]=W;
            G[Y][X]=W;
        }

        FW(N);

        printf("Case #%d\n",Case++);

        for(int i=1;i<=Q;i++)
        {
            cin>>X>>Y;

            if(G[X][Y]==INT_MAX) printf("no path\n");
            else printf("%lld\n",G[X][Y]);
        }
    }

    return 0;
}
