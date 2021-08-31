#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000000+7
#define PI 2*acos(0.0)

ll A[1000004]={0},S[1000004]={0},E[1000004]={0};

int main()
{
    ll T,N,M,X,Y,W,K,Q,R,P;

    cin>>T;

    for(ll C=1;C<=T;C++)
    {
        cin>>N>>M;

        for(int i=1;i<=M;i++)
        {
            cin>>X>>Y;
            S[X]++;
            E[Y]++;
        }

        for(int i=1;i<=N;i++)
        {
            A[i]+=A[i-1]+S[i];

            A[i+1]-=E[i];
        }

        ll MAX=0,I=0;

        for(int i=1;i<=N;i++)
        {
            if(A[i]>MAX)
            {
                MAX=A[i];
                I=i;
            }
        }

        printf("Case %lld: %lld %lld\n",C,I,MAX);

        memset(A,0,sizeof(A));
        memset(S,0,sizeof(S));
        memset(E,0,sizeof(E));
    }

    return 0;
}

