
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
    ios_base:: sync_with_stdio(false); cin.tie(0); cout.precision(20);
}
ll max(ll a,ll b)
{
    if(a>b) return a; else return b;
}
ll min(ll a,ll b)
{
    if(a<b) return a; else return b;
}
ll pow(ll B,ll P)
{
    ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;
}

///***Faizul***CSE**4th batch**BU

struct abc
{
    int value;
    int index;
    abc(int a,int b)
    {
        value=a; index=b;
    }
};

int inversion(string S,int N)
{
    int Count=0;
    for(int i=0;i<N;i++)
    {
        int C=0;
        for(int j=i+1;j<N;j++)
        {
            if(S[j]<S[i]) C++;
        }
        Count+=C;
    }
    return Count;
}


bool faizul (abc a,abc b)
{
    if(a.value==b.value) return a.index<b.index;
    return a.value<b.value;
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
        int N,M;

        cin>>N>>M;

        string S[100000];

        vector <abc> V;

        for(int i=1;i<=M;i++)
        {
            cin>>S[i];
            int X=inversion(S[i],N);
            V.pb(abc(X,i));
        }
        sort(V.begin(),V.end(),faizul);

        for(int i=0;i<M;i++)
        {
            int X=V[i].index;
            cout<<S[X]<<endl;
        }
        if(T) cout<<endl;

    }


    return 0;
}
