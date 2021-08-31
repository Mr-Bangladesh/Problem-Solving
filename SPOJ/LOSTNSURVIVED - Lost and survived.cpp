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

ll par[200005],d[200005];

ll Find(ll r){
    if(r==par[r]) return r;
    else return par[r]=Find(par[r]);
}
set< pair<ll,ll> > s;
ll mx=0;
ll Union(ll x,ll y){
    ll px=Find(x); ll py=Find(y);
    if(px!=py){
        par[py]=px;
        s.erase(mp(d[px],px));
        s.erase(mp(d[py],py));
        d[px]+=d[py];
        mx=max(mx,d[px]);
        s.insert(mp(d[px],px));
    }
//    for(auto i:s){
//        cout<<i.first<<"  "<<i.second<<endl;
//    }
    auto it=s.begin();
    auto it1=s.end(); it1--;
    ll ans=(it1->first) - (it->first);
    return ans;
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n>>q;

    for(int i=1;i<=n;i++){
        par[i]=i;
        d[i]=1;
        s.insert(mp(1,i));
    }

    while(q--){
        cin>>x>>y;
        ll ans=Union(x,y);
        cout<<ans<<endl;
    }

    return 0;
}



