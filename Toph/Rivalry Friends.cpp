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
#define MAXX 10000000
vector <ll> Primes;
ll status[MAXX/32];
bool check(ll N,ll pos){
    return (bool) (N & (1<<pos));
}
ll SET(ll N,ll pos){
    return (N | (1<<pos));
}
void sieve(){
    Primes.pb(2);
    for(ll i=3;i<=MAXX;i+=2){
        if(check(status[i/32],i%32)==0){
            Primes.pb(i);
            for(ll j=i*i;j<=MAXX;j+= i*2){
                status[j/32]=SET(status[j/32],j%32);
            }
        }
    }
}
ll A[100005];
ll lim=100000;
void phi()
{
	for(ll i=1;i<=lim;i++) A[i]=i;
	for(ll x:Primes){
    	for(ll i=x;i<=lim;i+=x){
        	A[i]=(A[i]*(x-1))/x;
    	}
	}
}
ll tree[400008],a[100005];
void build(ll node,ll b,ll e)
{
    if(b==e){
        tree[node]=A[a[b]];
        return;
    }
    ll left=node*2; ll right=node*2+1; ll mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
ll Query(ll node,ll b,ll e,ll i,ll j)
{
    if(e<i || b>j) return 0;
    else if(b>=i && e<=j) return tree[node];
    ll mid=(b+e)/2; ll left=node*2; ll right=left+1;
    ll P1=Query(left,b,mid,i,j);
    ll P2=Query(right,mid+1,e,i,j);
     return P1+P2;
}
void update(ll node,ll b,ll e,ll i,ll value)
{
    if(i<b || i>e) return;
    else if(i==b && b==e)
    {
        tree[node]=A[value];
        return;
    }
    ll left=node*2; ll right=left+1; ll mid=(b+e)/2;
    if(i<=mid) update(left,b,mid,i,value);
    else update(right,mid+1,e,i,value);
    tree[node]=tree[right] + tree[left];
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    sieve();
    phi();
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(q--){
        cin>>r>>x>>y;
        if(r==1){
            update(1,1,n,x,y);
        }
        else{
            ll ans=Query(1,1,n,x,y);
            cout<<ans<<endl;
        }
    }

    return 0;
}
