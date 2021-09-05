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
stack<int> s;
unordered_map<int, vector<int> > g;
ll ssize[500005];
void dfs(int u,int par){
    ssize[u]=1;
    for(auto v:g[u]){
        if(v==par) continue;
        dfs(v,u);
        ssize[u]+=ssize[v];
    }
    s.push(u);
}
unordered_map<int,int> node,node1;
int a[500005];
vector<int> tree[2000005];
void build(int n,int b,int e){
    if(b==e){
        tree[n].pb(a[node[b]]);
        return;
    }
    int mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    merge(tree[n*2].begin(),tree[n*2].end(),tree[n*2+1].begin(),tree[n*2+1].end(),back_inserter(tree[n]));
}
ll query(int n,int b,int e,int i,int j,int value){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j){
        int x=lower_bound(tree[n].begin(),tree[n].end(),value)-tree[n].begin();
        return tree[n].size()-x;
    }
    int mid=(b+e)/2;
    int x=query(n*2,b,mid,i,j,value);
    int y=query(n*2+1,mid+1,e,i,j,value);
    return x+y;
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    int t,n,m,x,y,w,k,q,r,p,cs;

    scanf("%d %d",&n,&m);
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        g[i].pb(x);
        g[x].pb(i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    dfs(1,-1);
    int idx=1;
    while(!s.empty()){
        int u=s.top(); s.pop();
        node[idx]=u;
        node1[u]=idx;
        idx++;
    }
    build(1,1,n);
    int v;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&v,&x);
        int ans=query(1,1,n,node1[v],node1[v]+ssize[v]-1,x);
        printf("%d\n",ans);
    }

    return 0;
}
