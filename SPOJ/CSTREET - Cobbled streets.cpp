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
struct ff{
    ll u,v,w;
    ff(ll a,ll b,ll c){
        u=a; v=b;w=c;
    }
};
ll par[1006];
ll Find(ll r){
    if(r==par[r]) return r;
    else return par[r]=Find(par[r]);
}
bool faizul(ff a,ff b){
    return a.w<b.w;
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    while(t--){
        cin>>k>>n>>m;

        for(int i=1;i<=n;i++) par[i]=i;

        vector<ff> edge;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>w;
            edge.pb(ff(x,y,w));
        }

        sort(edge.begin(),edge.end(),faizul);

        ll cnt=0;
        for(auto I:edge){
            ll px=Find(I.u); ll py=Find(I.v);
            if(px!=py){
                cnt+=(I.w);
                par[py]=px;
            }
        }
        cout<<(cnt*k)<<endl;
    }

    return 0;
}



