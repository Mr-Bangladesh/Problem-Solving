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
ll a[100005];
vector<ll> tree[500005];
void build(ll n,ll b,ll e){
    if(b==e){
        tree[n].pb(a[b]);
        return;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    merge(tree[n*2].begin(),tree[n*2].end(),tree[n*2+1].begin(),tree[n*2+1].end(),back_inserter(tree[n]));
    //for(auto it:tree[n]) cout<<it<<" "; cout<<endl;
}
ll query(ll n,ll b,ll e,ll i,ll j,ll v){
    //cout<<n<<" "<<b<<" "<<e<<" "<<i<<" "<<j<<" "<<v<<endl;
    if(b>j || e<i) return 0;
    if(b>=i && e<=j){
        ll x=lower_bound(tree[n].begin(),tree[n].end(),v)-tree[n].begin();
        return x;
    }
    ll mid=(b+e)/2;
    ll x=query(n*2,b,mid,i,j,v);
    ll y=query(n*2+1,mid+1,e,i,j,v);
    return x+y;
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    build(1,1,n);
    for(int i=1;i<=n;i++){
        x=query(1,1,n,i+1,n,a[i]);
        ans+=x;
    }

    cout<<ans<<endl;

    return 0;
}

