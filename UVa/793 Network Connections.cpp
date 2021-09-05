///***Bismillahir Rahmanir Rahim***

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
///cin.ignore();
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}
ll max(ll a,ll b)
{
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a<b) return a;
    else return b;
}
ll pow(ll B,ll P)
{
    ll S=1;
    for(ll i=1; i<=P; i++) S=S*B;
    return S;
}
int fx4[]= {1,-1,0,0};
int fy4[]= {0,0,1,-1};


///***Faizul***CSE**4th batch**BU

int Parent[10000];

void initialize(int N)
{
    for(int i=0;i<=N;i++) Parent[i]=i;
}

int Find(int r)
{
    if(Parent[r]==r) return r;
    Parent[r]=Find(Parent[r]);
    return Parent[r];
}

void Union(int x,int y)
{
    int PX=Find(x);
    int PY=Find(y);

    if(PX!=PY) Parent[PX]=PY;
}

int main()
{
    FastIO();

    //freopen("1.txt","r",stdin);

    int T;

    cin>>T;

    while(T--)
    {
        int nodes;
        cin>>nodes;

        cin.ignore();
        string S;

        initialize(nodes);

        int ase=0,nai=0;

        while(getline(cin,S))
        {
            if(S[0]=='\0') break;

            stringstream faizul(S);
            char C;
            int a,b;

            faizul>>C>>a>>b;

            if(C=='c')
                Union(a,b);

            if(C=='q')
            {
                int X=Find(a); int Y=Find(b);

                if(X==Y) ase++;
                else nai++;
            }

        }

        cout<<ase<<","<<nai<<endl;

        if(T) cout<<endl;

        memset(Parent,0,sizeof(Parent));
    }



    return 0;
}
