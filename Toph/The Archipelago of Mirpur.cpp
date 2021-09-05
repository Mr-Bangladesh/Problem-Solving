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
map<ll, pair<ll,ll> > N;
struct ff{
    ll u,v; double w;
    ff(ll a,ll b,double c){
        u=a; v=b; w=c;
    }
};
vector<ff> E;
bool faizul(ff a,ff b){
    return a.w<b.w;
}
ll par[2000];
double res[2000];
ll Find(ll r){
    if(par[r]==r) return r;
    else return par[r]=Find(par[r]);
}
ll idx;
void Union(ll x,ll y,double w){
    ll px=Find(x); ll py=Find(y);
    if(px!=py){
        par[py]=px;
        res[idx]=w;
        idx--;
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        N[i]={x,y};
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            x=N[i].first-N[j].first;
            y=N[i].second-N[j].second;
            x=x*x;
            y=y*y;
            double d=sqrt(double(x+y));
            E.pb(ff(i,j,d));
        }
    }

    sort(E.begin(),E.end(),faizul);

//    for(auto it:E){
//        cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
//    }
    idx=n-1;
    res[idx]=0;

    for(int i=1;i<=n;i++) par[i]=i;

    for(auto it:E){
        Union(it.u,it.v,it.w);
    }

//    for(int i=1;i<=n;i++){
//        cout<<i<<" "<<res[i]<<endl;
//    }
    cin>>q;
    while(q--){
        cin>>n;
        printf("%.9f\n",res[n]);
    }

    return 0;
}
