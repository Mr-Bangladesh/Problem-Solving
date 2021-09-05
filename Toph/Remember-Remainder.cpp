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

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n>>k;
    ll a[n+5];
    map<ll,ll> cnt;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]%k]++;
    }
    ll ans=0;
    for(int i=0;i<k;i++){
        if(cnt[i]>n/k){
            x=cnt[i]-(n/k);
            cnt[(i+1)%k]+=x;
            ans+=(x);
            cnt[i]-=x;
        }
    }
    //cout<<ans<<endl;
    //for(int i=0;i<k;i++) cout<<cnt[i]<<" "; cout<<endl;
    for(int i=0;i<k;i++){
        if(cnt[i]>n/k){
            x=cnt[i]-(n/k);
            cnt[(i+1)%k]+=x;
            ans+=(x);
            cnt[i]-=x;
        }
    }

    cout<<ans<<endl;

    return 0;
}
