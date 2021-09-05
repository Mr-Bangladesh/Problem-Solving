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

int Parent1[10001];

int Parent2[10001];

void initialize(int N)
{
    for(int i=0; i<=N; i++)
    {
        Parent1[i]=i;
        Parent2[i]=i;
    }
}

int Find1(int r)
{
    if(Parent1[r]==r) return r;

    Parent1[r]=Find1(Parent1[r]);
    return Parent1[r];
}

int Find2(int r)
{
    if(Parent2[r]==r) return r;
    Parent2[r]=Find2(Parent2[r]);
    return Parent2[r];
}

void Union1(int x,int y)
{
    int PX=Find1(x);
    int PY=Find1(y);

    if(PX!=PY)
        Parent1[PY]=PX;
}

void Union2(int x,int y)
{
    int PX=Find2(x);
    int PY=Find2(y);

    if(PX!=PY) Parent2[PY]=PX;
}

int main()
{
    FastIO();

    //freopen("1.txt","r",stdin);

    int T;

    int O,x,y;


    while(cin>>T)
    {
        initialize(10001);

        while(cin>>O>>x>>y)
        {

            if(O==0 && x==0 && y==0) break;

            if(O==1)
                Union1(x,y);
            else if(O==2)
            {
                Union2(x,y);
            }
            else if(O==3)
            {
                int PX=Find1(x);
                int PY=Find1(y);

                if(PX==PY)
                {
                    int F1=Find2(x);
                    int F2=Find2(y);

                    cout<<F1<<" "<<F2<<endl;

                    if(F1==F2 || F1==PY || F2==PX) cout<<"-1"<<endl;

                    else cout<<1<<endl;
                }
                else cout<<0<<endl;

            }
            else if(O==4)
            {
                int PX=Find2(x);
                int PY=Find2(y);

                //if(PX==x && PY==y) cout<<"0"<<endl;
                if(PX==PY)
                {
                    int F1=Find1(x);
                    int F2=Find1(y);
                    if(F1==F2) cout<<"-1"<<endl;
                    else cout<<1<<endl;
                }
                else
                {
                    int F1=Find1(x);
                    int F2=Find1(y);
                    if(F1==PY) cout<<1<<endl;
                    else if(F2==PX) cout<<1<<endl;
                    else cout<<0<<endl;
//                if(PX==x)
//                {
//                    int F1=Find1(x);
//                    if(F1==PY) cout<<1<<endl;
//                    else cout<<0<<endl;
//                }
//                else if(PY==y)
//                {
//                    int F1=Find1(y);
//                    if(F1==PX) cout<<1<<endl;
//                    else cout<<0<<endl;
//                }
                }

            }
        }
    }

    return 0;
}
