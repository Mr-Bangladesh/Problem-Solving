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

int Parent[100000];

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

int ans;

void Union(int X,int Y)
{
    int PX=Find(X);
    int PY=Find(Y);
    if(PX!=PY)
    {
        Parent[PX]=PY;
        ans--;
    }
}

int main()
{
    FastIO();

    int N,M;

    int test=1;

    while(cin>>N>>M)
    {
        if(N==0 && M==0) break;

        int X,Y;

        initialize(N);

        ans=N;

        for(int i=0;i<M;i++)
        {
            cin>>X>>Y;
            Union(X,Y);
        }
        printf("Case %d: %d\n",test,ans);

        test++;

        memset(Parent,0,sizeof(Parent));
    }


    return 0;
}
