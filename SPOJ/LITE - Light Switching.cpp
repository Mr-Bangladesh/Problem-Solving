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
ll tree[500005],prop[500005];
void propagate(ll n,ll b,ll e){
    ll l=n*2; ll r=l+1;
    ll mid=(b+e)/2;
    prop[n]=0;
    prop[l]^=1; prop[r]^=1;
    tree[l]=mid-b+1-tree[l];
    tree[r]=e-mid-tree[r];
    tree[n]=tree[l]+tree[r];
}
void update(ll n,ll b,ll e,ll i,ll j){
    if(i>e || j<b) return;
    if(prop[n]){
        propagate(n,b,e);
    }
    if(b>=i && e<=j){
        prop[n]^=1;
        tree[n]=e-b+1-tree[n];
        return;
    }
    ll mid=(b+e)/2;
    update(n*2,b,mid,i,j);
    update(n*2+1,mid+1,e,i,j);
    tree[n]=tree[n*2]+tree[n*2+1];
}
ll query(ll n,ll b,ll e,ll i,ll j){
    if(i>e || j<b) return 0;
    if(prop[n]){
        propagate(n,b,e);
    }
    if(b>=i && e<=j){
        return tree[n];
    }
    ll mid=(b+e)/2;
    ll x=query(n*2,b,mid,i,j);
    ll y=query(n*2+1,mid+1,e,i,j);
    return x+y;
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n>>m;
    while(m--){
        cin>>q>>x>>y;
        if(!q){
            update(1,1,n,x,y);
        }
        else{
            ll ans=query(1,1,n,x,y);
            cout<<ans<<endl;
        }
    }

    return 0;
}

