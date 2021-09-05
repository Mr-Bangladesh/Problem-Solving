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

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    vector< pair<ll,ll> > power;
    for(int i=0;i<32;i++){
        power.pb(mp(1LL<<i,i));
    }

    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n==m){
            ll ans=log2(n)+1;
            cout<<ans<<endl; continue;
        }
        vector< pair<ll,ll> > v;
        ll lst=0;
        for(auto it:power){
            if(it.first>=n && it.first<=m){
                v.pb(it);
            }
            if(it.first<=m){
                lst=it.second+1;
            }
        }
//        for(auto it:v){
//            cout<<it.first<<" "<<it.second<<endl;
//        }
        ll l=n;
        ll ans=0;
        for(auto it:v){
            x=((it.first-l)*it.second)%MOD;
            cout<<it.first<<" "<<it.second<<" "<<x<<endl;
            ans=(ans+x)%MOD;
            l=it.first;
        }
        if(l<=m){
            x=((m-l+1)*lst)%MOD;
            ans=(ans+x)%MOD;
        }
        cout<<ans%MOD<<endl;
    }

    return 0;
}
