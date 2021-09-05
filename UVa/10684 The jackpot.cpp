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
    int N;

    while(scanf("%d",&N))
    {
        if(N==0) break;

        int A[20000];

        for(int i=1;i<=N;i++) scanf("%d",&A[i]);

        int sum=0,ans=0;

        for(int i=1;i<=N;i++)
        {
            sum+=A[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }

        if(ans==0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",ans);

    }

    return 0;
}
