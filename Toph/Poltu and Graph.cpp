#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
struct ff{
    ll u,v,w;
    ff(ll a,ll b,ll c){
        u=a; v=b; w=c;
    }
};
bool comp(ff a,ff b){
    return a.w<b.w;
}
ll par[300000],ssize[300000];
ll Find(ll r){
    if(par[r]==r) return r;
    else return par[r]=Find(par[r]);
}
void Union(ll x,ll y){
    ll px=Find(x);
    ll py=Find(y);
    if(px!=py){
        par[py]=px;
        ssize[px]+=ssize[py];
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        par[i]=i;
        ssize[i]=1;
    }
    vector<ff> g;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>w;
        g.pb(ff(x,y,w));
    }
    sort(g.begin(),g.end(),comp);
    cin>>q;
    vector<ff> query;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        query.pb(ff(x,i,y));
    }
    sort(query.begin(),query.end(),comp);
    ll ans[q+4]={0};
    for(int i=1;i<=q;i++) ans[i]=1;
    int i=0,j=0;
    while(i<q || j<m){
        if(i>=q) break;
        ll s=query[i].u; ll lim=query[i].w; ll idx=query[i].v;
        if(j>=m){
            ll ps=Find(s);
            ans[idx]=ssize[ps];
            i++;
            continue;
        }
        x=g[j].u; y=g[j].v; w=g[j].w;
        if(w<=lim){
            Union(x,y);
            j++;
            ll ps=Find(s);
            ans[idx]=ssize[ps];
        }
        else{
            ll ps=Find(s);
            ans[idx]=ssize[ps];
            i++;
        }
    }

    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;

    return 0;
}
