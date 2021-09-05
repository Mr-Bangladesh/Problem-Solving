
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

map<string,string> Parent;
map<string,int> circle;

string Find(string r)
{
    if(Parent[r]==r) return r;
    Parent[r]=Find(Parent[r]);
    return Parent[r];
}

void Union(string S1,string S2)
{
    string PX=Find(S1); string PY=Find(S2);

    if(PX!=PY)
    {
        Parent[PY]=PX;

        circle[PX]=circle[PX] + circle[PY];
    }
}


int main()
{
    FastIO();

    int T;

    cin>>T;

    while(T--)
    {
        int F;

        cin>>F;

        string S1,S2;

        for(int i=1;i<=F;i++)
        {
            cin>>S1>>S2;

            if(Parent[S1]=="")
            {
                Parent[S1]=S1;
                circle[S1]=1;
            }

            if(Parent[S2]=="")
            {
                Parent[S2]=S2;
                circle[S2]=1;
            }

            Union(S1,S2);

            string X=Parent[S1];
            cout<<circle[X]<<endl;
        }

        Parent.clear();
    }

    return 0;
}
