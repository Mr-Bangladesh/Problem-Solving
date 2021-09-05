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

int A;

vector <int> G[2000000];

int main()
{
    FastIO();

    //freopen("input.txt","r",stdin);

    int N,M;

    while(cin>>N>>M)
    {
        for(int i=1;i<=N;i++)
        {
            cin>>A;
            G[A].pb(i);
        }

        int K,V;

        for(int i=1;i<=M;i++)
        {
            cin>>K>>V;

            if(G[V].size()<K)
            {
                cout<<0<<endl;
                continue;
            }

            cout<<G[V][K-1]<<endl;
        }

        for(int i=1;i<=2000000;i++) G[i].clear();

    }

    return 0;
}
