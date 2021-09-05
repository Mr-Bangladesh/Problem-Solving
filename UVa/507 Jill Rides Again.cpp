#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll pow(ll B,ll P) { ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;}
int fx4[]={1,-1,0,0}; int fy4[]={0,0,1,-1};


int main()
{
    //freopen("1.txt","r",stdin);
    int TC;

    scanf("%d",&TC);

    for(int C=1;C<=TC;C++)
    {
        int N,A[20009]={0};

        scanf("%d",&N);

        for(int i=1;i<N;i++) scanf("%d",&A[i]);

        int S=1,E=1; int ans=0,sum=0;

        for(int i=1;i<N;i++)
        {
            sum+=A[i];

            if(sum>=ans)
            {
                ans=sum;
                E=i+1;
            }
            if(sum<0)
            {
                sum=0; S=i+1;
            }
        }
        if(ans==0) printf("Route %d has no nice parts\n",C);
        else printf("The nicest part of route %d is between stops %d and %d\n",C,S,E);
    }

    return 0;
}
