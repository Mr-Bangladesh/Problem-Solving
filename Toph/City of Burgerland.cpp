/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll a[100005];
vector<ll> t[400008];
vector<ll> sum[400008];
void build(ll n,ll b,ll e){
    if(b==e){
        t[n].pb(a[b]);
        sum[n].pb(a[b]);
        return;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    merge(t[n*2].begin(),t[n*2].end(),t[n*2+1].begin(),t[n*2+1].end(),back_inserter(t[n]));
    ll x=t[n].size();
    sum[n].pb(t[n][0]);
    ll cur=t[n][0];
    for(int i=1;i<x;i++){
        cur+=t[n][i];
        sum[n].pb(cur);
    }
}
ll query(ll n,ll b,ll e,ll i,ll j,ll k){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j){
        ll y=upper_bound(t[n].begin(),t[n].end(),k)-t[n].begin();
        if(y==0) return 0;
        //cout<<b<<" "<<e<<" "<<i<<" "<<j<<endl;
        //cout<<y<<endl;
        //for(int x:t[n]) cout<<x<<" "; cout<<endl;
        //for(int x:sum[n]) cout<<x<<" "; cout<<endl;
        ll cur=k*y-sum[n][y-1];
        return cur;
    }
    ll mid=(b+e)/2;
    ll x=query(n*2,b,mid,i,j,k);
    ll y=query(n*2+1,mid+1,e,i,j,k);
    return x+y;

}
int main()
{
    ll n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    ll l,r,cap;
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&l,&r,&cap);
        ll res=query(1,1,n,l,r,cap);
        printf("%lld\n",res);
    }

    return 0;
}


