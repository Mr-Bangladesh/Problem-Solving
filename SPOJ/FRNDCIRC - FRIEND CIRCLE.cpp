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

map<string,string> par;
map<string,ll> d;
string Find(string r){
    if(par[r]==r) return r;
    else return par[r]=Find(par[r]);
}
ll Union(string x,string y){
    string px=Find(x); string py=Find(y);
    if(px!=py){
        par[py]=px;
        d[px]+=d[py];
    }
    return d[px];
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;

    while(t--){
        cin>>n;
        string a,b;
        for(int i=1;i<=n;i++){
            cin>>a>>b;
            if(par[a]==""){
                par[a]=a;
                d[a]=1;
            }
            if(par[b]==""){
                par[b]=b;
                d[b]=1;
            }
            ll ans=Union(a,b);
            cout<<ans<<endl;
        }
        d.clear();
        par.clear();
    }

    return 0;
}



