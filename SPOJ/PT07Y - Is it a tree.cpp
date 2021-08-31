#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

map<ll,vector<ll> > g;
map<ll,ll> mark,par;
bool check=true;
void dfs(ll u){
    mark[u]=1;
    for(ll v:g[u]){
        if(!mark[v]){
            par[v]=u;
            dfs(v);
        }
        else{
            if(v!=par[u]){
                check=false;
            }
        }
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n>>m;

    for(int i=1;i<=m;i++){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    for(int i=1;i<=n;i++){
        if(!mark[i]){
            dfs(i);
        }
    }

    if(check) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}



