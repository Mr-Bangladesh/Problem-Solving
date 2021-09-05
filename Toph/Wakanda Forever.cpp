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
vector<ff> E;
bool faizul(ff a,ff b){
    return a.w<b.w;
}
ll par[200005];
ll Find(ll r){
    if(par[r]==r) return r;
    else return par[r]=Find(par[r]);
}
ll comp,ans;
void Union(ll x,ll y,ll w){
    ll px=Find(x); ll py=Find(y);
    if(px!=py){
        par[py]=px;
        comp--;
        ans+=w;
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs,d;

    cin>>n>>m>>d;
    ll a[n+3];
    ll cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!a[i]) cnt++;
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y>>w;
        if(a[x]>0 && a[y]>0){
            E.pb(ff(x,y,w));
        }
    }
    sort(E.begin(),E.end(),faizul);
    for(int i=1;i<=n;i++) par[i]=i;
    comp=n-cnt-1;
    for(auto it:E){
        Union(it.u,it.v,it.w);
    }
    if(comp>=1){
        ans+=(comp*d);
    }
    cout<<ans<<endl;

    return 0;
}
