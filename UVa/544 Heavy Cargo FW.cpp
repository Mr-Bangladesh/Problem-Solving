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

map <pair<string,string> , ll> G;

vector <string> V;

void FW(int N)
{
    for(ll k=0;k<N;k++)
    {
        for(ll i=0;i<N;i++)
        {
            for(ll j=0;j<N;j++)
            {
                if(i==j) continue;
                ll A=min(G[mp(V[i],V[k])],G[mp(V[k],V[j])]);

                //if(G[mp(V[i],V[j])]==INT_MAX) G[mp(V[i],V[j])]=0;

                G[mp(V[i],V[j])]=max(G[mp(V[i],V[j])],A);

                //cout<<V[i]<<" "<<V[j]<<" "<<G[mp(V[i],V[j])]<<endl;

            }
        }
    }
}

int main()
{

    //freopen("1.txt","r",stdin);

    ll N,R;

    int C=1;

    while(cin>>N>>R)
    {
        if(N==0 && R==0) break;

        string X,Y; ll W;

        set<string> Nodes;

        for(int i=0;i<R;i++)
        {
            cin>>X>>Y>>W;
            Nodes.insert(X);
            Nodes.insert(Y);
            G[mp(X,Y)]=W;
            G[mp(Y,X)]=W;
        }

        for(auto it=Nodes.begin();it!=Nodes.end();it++) V.pb(*it);

        string Source,des;

        cin>>Source>>des;

        FW(N);

        ll ans=G[mp(Source,des)];

        printf("Scenario #%d\n",C);
        printf("%d tons\n\n",ans);

        C++;

        G.clear();
        V.clear();
    }

    return 0;
}
