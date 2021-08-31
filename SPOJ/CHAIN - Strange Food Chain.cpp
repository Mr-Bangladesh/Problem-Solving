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
ll par[50004];

ll Find(ll r){
    if(r==par[r]) return r;
    else return par[r]=Find(par[r]);
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;

    while(t--){
        cin>>n>>k;
        ll cnt=0;
        for(int i=1;i<=n;i++) par[i]=i;
        for(int i=1;i<=k;i++){
            ll c;
            cin>>c>>x>>y;
            if(x>n || y>n || x<1 || y<1){
                cnt++;
                continue;
            }
            if(c==1){
                if(x==y) continue;
            }
            else{
                if(x==y){
                    cnt++;
                    continue;
                }
                ll px=Find(x);
                ll py=Find(y);
                if(px!=py){

                }
            }
        }
    }

    return 0;
}



