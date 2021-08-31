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

map<ll, vector<ll> > g;
map<ll,bool>mark;
map<ll,ll> color;
bool check=true;

void dfs(ll u){
    mark[u]=true;
    for(ll v:g[u]){
        if(!mark[v]){
            if(color[u]==1) color[v]=2;
            else color[v]=1;
            dfs(v);
        }
        else{
            if(color[u]==color[v]){
                check=false; //cout<<u<<" "<<v<<endl;
            }
        }
    }
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    for(cs=1;cs<=t;cs++){
        cin>>n>>m;
        while(m--){
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        for(int i=1;i<=n;i++){
            if(!mark[i]){
                color[i]=1;
                dfs(i);
            }
        }
        if(check){
            printf("Scenario #%lld:\nNo suspicious bugs found!\n",cs);
        }
        else{
            printf("Scenario #%lld:\nSuspicious bugs found!\n",cs);
        }
        mark.clear();
        color.clear();
        g.clear();
        check=true;
    }

    return 0;
}



