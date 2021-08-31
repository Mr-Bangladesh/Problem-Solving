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
ll par[20000],d[20000];
ll Find(ll r){
    if(r==par[r]) return r;
    else return par[r]=Find(par[r]);
}
void Union(ll x,ll y){
    ll px=Find(x); ll py=Find(y);
    if(px!=py){
        par[py]=px;
        d[px]+=d[py];
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            par[i]=i;
            d[i]=1;
        }
        ll in[n+5]={0},out[n+5]={0};
        for(int i=1;i<=n;i++){
            cin>>k;
            while(k--){
                cin>>x;
                Union(i,x);
                in[x]++;
                out[i]++;
            }
        }
        ll cnt=0;
        for(int i=1;i<=n;i++){
            if(out[i]==0 && d[Find(i)]) cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}



