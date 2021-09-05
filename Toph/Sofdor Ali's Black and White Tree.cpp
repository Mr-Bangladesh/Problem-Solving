#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair

map<ll, vector<ll> > g;
map<ll,ll> color;
map<ll,ll> b,w;
ll ans=0;
void dfs(ll u,ll par){
    if(color[u]==0) b[u]=1;
    else w[u]=1;
    for(auto v:g[u]){
        if(par==v) continue;
        dfs(v,u);
        b[u]+=b[v];
        w[u]+=w[v];
    }
    ans=max(ans,b[u]-w[u]);
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y;
    cin>>n;
    ll cnt=0;
    for(int i=0;i<n;i++){
        cin>>color[i];
        if(color[i]==1) cnt++;
    }
    for(int i=1;i<n;i++){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(0,-1);

    cout<<ans+cnt<<endl;

    return 0;
}



