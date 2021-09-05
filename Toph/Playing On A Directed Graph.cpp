/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
struct ff{
    int u,v,w;
};
vector<ff> g;
int d[505];
bool bellmanFord(int n){
    for(int i=1;i<n;i++){
        for(ff x:g){
            if(d[x.u]+x.w<d[x.v]){
                d[x.v]=d[x.u]+x.w;
            }
        }
    }
    for(ff x:g){
        if(d[x.u]+x.w<d[x.v]){
            return false;
        }
    }
    return true;
}
int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.pb({u,v,w});
    }

    bool check=bellmanFord(n);
    if(!check){
        cout<<"NO"<<endl; return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){
        cout<<d[i];
        if(i!=n) cout<<" ";
    }

    return 0;
}

