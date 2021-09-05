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

map<string,int> Size;
map<string,string> Parent;

string Find(string r)
{
    if(Parent[r]==r) return r;
    Parent[r]=Find(Parent[r]);
    return Parent[r];
}

void Union(string X,string Y)
{
    string PX=Find(X); string PY=Find(Y);

    if(PX!=PY)
    {
        Parent[PX]=PY;
        Size[PY]+=Size[PX];
    }
}

int main()
{
    FastIO();

    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    int R,C;

    while(cin>>C>>R)
    {
        if(C==0 && R==0) break;

        string creature[100000];

        for(int i=0;i<C;i++)
        {
            cin>>creature[i];
            Parent[creature[i]]=creature[i];
            Size[creature[i]]=1;
        }
        string U,V;
        int MAX=0;
        for(int i=0;i<R;i++)
        {
            cin>>U>>V;

            Union(U,V);

            //int X=Size[V];
            int Y=Size[U];
            MAX=max(MAX,Y);

        }
        cout<<MAX<<endl;

        Parent.clear();
        Size.clear();
    }

    return 0;
}
