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

void Union(ll x,ll y,ll m){
    ll px=Find(x);ll py=Find(y);
    if(px!=py){
        ll tmp=d[px]+d[py];
        if(tmp>m) return;
        par[py]=px;
        d[px]+=d[py];
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
        d[i]=1;
    }

    cin>>q;

    while(q--){
        char ch;
        cin>>ch;
        if(ch=='A'){
            cin>>x>>y;
            Union(x,y,m);
        }
        else if(ch=='E'){
            cin>>x>>y;
            if(Find(x)==Find(y)){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }
        else{
            cin>>x;
            cout<<d[Find(x)]<<endl;
        }
    }

    return 0;
}



