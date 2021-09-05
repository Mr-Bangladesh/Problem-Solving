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

vector<int> g[100002];
char c[100002];
int parent[100002],deg[100002];
string t="tareq&shawon";
bool check;
int res;
void dfs(int u,int par,int idx){
    //cout<<u<<" "<<par<<" "<<idx<<" "<<c[u]<<" "<<endl;
    int tmp=idx;

    //cout<<u<<" "<<c[u]<<" "<<t[idx]<<" "<<idx<<endl;
    if(c[u]==t[idx]){
        tmp++;
    }
//    if(tmp==12){
//        check=true;
//        if(deg[u]==1){
//            res=min(res,u);
//        }
//    }

    if(tmp==12 && check==false){
        check=true;
        res=u;
    }

    for(int v:g[u]){
        if(v==par) continue;
        parent[v]=u;
        //cout<<u<<" "<<v<<" "<<c[v]<<" "<<t[idx]<<endl;

            dfs(v,u,tmp);

    }
}
vector<int> tmp;
bool mark=false;
void f(int u,int par){
    for(int v:g[u]){
        if(v==par) continue;
        if(mark==false ) tmp.pb(v);
        if(deg[v]==1){
            mark=true;
        }
        f(v,u);
    }
}

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            g[i].clear();
            parent[i]=-1;
            deg[i]=0;
        }
        int x,y;
        for(int i=1;i<n;i++){
            scanf("%d %d",&x,&y);
            deg[x]++;
            deg[y]++;
            g[x].pb(y);
            g[y].pb(x);
        }
        //cin.ignore();
        for(int i=1;i<=n;i++){
            getchar();
            scanf("%c",&c[i]);
        }
        //for(int i=1;i<=n;i++) cout<<c[i]<<" "; cout<<endl;
        for(int i=1;i<=n;i++){
            sort(g[i].begin(),g[i].end());
        }

        check=false;
        res=n+1;

        dfs(1,-1,0);
        if(!check){
            printf("Case %d: NO\n",cs++);
            continue;
        }
        printf("Case %d: YES\n",cs++);
        int cur=res;
        vector<int> ans;
        while(cur!=-1){
            ans.pb(cur);
            cur=parent[cur];
        }
        reverse(ans.begin(),ans.end());

        tmp.clear();
        mark=false;
        f(res,parent[res]);
        for(int x:tmp) ans.pb(x);

        for(int i=0;i<ans.size();i++){
            if(i>0) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }

    return 0;
}


