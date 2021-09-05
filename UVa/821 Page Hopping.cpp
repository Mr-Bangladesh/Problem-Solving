///***Bismillahir Rahmanir Rahim***
///***Faizul***CSE**4th batch**BU
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
///cin.ignore();
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll max(ll a,ll b)
{
    if(a>=b) return a;
    else return b;
}

ll graph[1000][1000];

set <ll> nodes;
set <ll> :: iterator k;
set <ll> :: iterator i;
set <ll> :: iterator j;

double FW()
{
    for(k=nodes.begin();k!=nodes.end();k++)
    {
        for(i=nodes.begin();i!=nodes.end();i++)
        {
            for(j=nodes.begin();j!=nodes.end();j++)
            {
                if(*i==*j) continue;

                graph[*i][*j]=min(graph[*i][*j],graph[*i][*k]+graph[*k][*j]);
            }
        }
    }

    int sum=0;

    for(i=nodes.begin();i!=nodes.end();i++)
    {
        for(j=nodes.begin();j!=nodes.end();j++)
        {
            if(*i!=*j) sum+=graph[*i][*j];
        }
    }
    int N=nodes.size();

    int M=(N*N)-N;

    double ans=(double)sum/double(M);

    return ans;

}

int main()
{
    FastIO();

    ll a,b;

    ll test=1;

    while(cin>>a>>b)
    {
        if(a==0 && b==0) break;

        for(ll I=0; I<1000; I++)
        {
            for(ll J=0; J<1000; J++)
            {
                if(J==I) graph[I][J]=0;

                else graph[I][J]=INT_MAX;
            }
        }


        graph[a][b]=1; nodes.insert(a); nodes.insert(b);

        while(cin>>a>>b)
        {
            if(a==0 && b==0) break;
            graph[a][b]=1;
            nodes.insert(a); nodes.insert(b);
        }

        double ans=FW();

        nodes.clear();

        printf("Case %lld: average length between pages = %.3f clicks\n",test,ans);
        test++;

    }


    return 0;
}
