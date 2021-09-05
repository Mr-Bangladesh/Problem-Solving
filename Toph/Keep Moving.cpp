/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

vector<int> g[100005];
int dp[100005],mark[100005];
int dfs(int u){
    if(mark[u]) return dp[u];
    mark[u]=1;
    int cur=false;
    for(int v:g[u]){
        if(!dfs(v)){
            cur=true;
            break;
        }
    }
    return dp[u]=cur;
}

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m,x,u,v;
        scanf("%d %d %d",&n,&m,&x);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            g[u].pb(v);
        }
        if(dfs(x)) printf("Case %d: Yes\n",cs++);
        else printf("Case %d: No\n",cs++);

        for(int i=1;i<=n;i++){
            g[i].clear();
            dp[i]=mark[i]=0;
        }
    }

    return 0;
}


