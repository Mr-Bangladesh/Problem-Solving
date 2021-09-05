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
map<ll,vector<ll> > g;
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    string a,b;
    cin>>a>>b;
    int l1=a.length(), l2=b.length();
    for(int i=0;i<l2;i++){
        for(int j=0;j<l1;j++){
            if(b[i]==a[j]){
                g[i].pb(j);
            }
        }
    }
    ll ans=INF;
    for(int i=0;i<g[0].size();i++){
        x=g[0][i];
        ll cnt=0; bool check=true;
        for(int j=1;j<l2;j++){
            auto it=upper_bound(g[j].begin(),g[j].end(),x); ll idx=it-g[j].begin();
            if(it!=g[j].end()){
                cnt+=(g[j][idx]-x);
                //cout<<a[x]<<" "<<a[g[j][idx]]<<" "<<x<<" "<<g[j][idx]<<endl;
                x=g[j][idx];
            }
            else{
                check=false;
                break;
            }
        }
        if(check){
            //cout<<cnt<<endl;
            ans=min(ans,cnt);
        }
    }

    cout<<ans<<endl;

    return 0;
}
