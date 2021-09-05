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
vector<int> a[100005];
int mark[100005];
void bfs(int s){
    mark[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:g[u]){
            if(!mark[v]){
                mark[v]=1;
                q.push(v);
                a[u].pb(v);
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n,m;
        scanf("%d %d",&n,&m);

        for(int i=1;i<=n;i++){
            g[i].clear();
            a[i].clear();
            mark[i]=0;
        }

        int x,y;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            x++; y++;
            g[x].pb(y);
            g[y].pb(x);
        }
        for(int i=1;i<=n;i++){
            sort(g[i].begin(),g[i].end());
        }

        bfs(1);

        int q;
        printf("Case %d:\n",cs);
        scanf("%d",&q);
        while(q--){
            scanf("%d %d",&x,&y);
            x++; y++;
            //for(int f:a[x]) cout<<f<<" "; cout<<endl;
            if(binary_search(a[x].begin(),a[x].end(),y)){
                printf("Yes\n");
            }
            else if(binary_search(a[y].begin(),a[y].end(),x)){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }

    return 0;
}


