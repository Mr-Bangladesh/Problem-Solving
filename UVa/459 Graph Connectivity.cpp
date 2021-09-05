///***Bismillahir Rahmanir Rahim***

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


///***Faizul***CSE**4th batch**BU
int parent[1000];

void initialize(int N)
{
    for(int i=0;i<=N;i++) parent[i]=i;
}

int Find(int r)
{
    if(parent[r]==r) return r;
    parent[r]=Find(parent[r]);
    return parent[r];
}
int ans;
void Union(int x,int y)
{
    int PX=Find(x);
    int PY=Find(y);
    if(PX!=PY)
    {
        parent[PX]=PY;
        ans--;
    }
}


int main()
{
    FastIO();

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int T;

    cin>>T;

    while(T--)
    {
        string nodes;
        cin>>nodes;

        int N=nodes[0]-64;

        //cout<<nodes<<" "<<N<<endl;

        initialize(N);

        string edge;

        cin.ignore();
        ans=N;

        while(getline(cin,edge))
        {
            if(edge[0]=='\0') break;

            int X=edge[0]-64;
            int Y=edge[1]-64;

            Union(X,Y);

        }
        cout<<ans<<endl;

        if(T) cout<<endl;

        memset(parent,0,sizeof(parent));
    }

    return 0;
}
