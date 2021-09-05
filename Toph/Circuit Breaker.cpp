/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int> g[n+2];
        int mark[n+2][n+2];
        memset(mark,0,sizeof(mark));
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            x++; y++;
            g[x].pb(y);
            g[y].pb(x);
            mark[x][y]=1;
            mark[y][x]=1;
        }
        if(n<3){
            printf("Case %d: No\n",cs);
            continue;
        }
        bool check=true;
        for(int i=1;i<=n;i++){
            for(int u:g[i]){
                for(int v:g[u]){
                    if(mark[i][v]==1 || mark[v][i]==1){
                        check=false; break;
                    }
                }
                if(!check) break;
            }
            if(!check) break;
        }
        //cout<<check<<endl;
        if(!check){
            int cnt=3*n-6;
            if(m<=cnt){
                printf("Case %d: No\n",cs);
            }
            else{
                printf("Case %d: Yes\n",cs);
            }
        }
        else{
            int cnt=2*n-4;
            if(m<=cnt){
                printf("Case %d: No\n",cs);
            }
            else{
                printf("Case %d: Yes\n",cs);
            }
        }
    }

    return 0;
}


