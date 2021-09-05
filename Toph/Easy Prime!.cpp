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

ll a[100005],tree[400008];
void build(ll n,ll b,ll e){
    if(b==e){
        if(binary_search(Primes.begin(),Primes.end(),a[b])){
            tree[n]=1;
        }
        return;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    tree[n]=tree[n*2]+tree[n*2+1];
}
void update(ll n,ll b,ll e,ll i,ll value)
{
    if(i<b || i>e) return;
    else if(i==b && b==e)
    {
        if(binary_search(Primes.begin(),Primes.end(),value)){
            tree[n]=1;
        }
        else tree[n]=0;
        return;
    }
    ll mid=(b+e)/2;
    update(n*2,b,mid,i,value);
    update(n*2+1,mid+1,e,i,value);
    tree[n]=tree[n*2]+tree[n*2+1];
}
ll query(ll n,ll b,ll e,ll i,ll j){
    if(e<i || b>j) return 0;
    else if(b>=i && e<=j) return tree[n];
    ll mid=(b+e)/2;
    ll P1=query(n*2,b,mid,i,j);
    ll P2=query(n*2+1,mid+1,e,i,j);
     return P1+P2;
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    sieve();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    cin>>q;
    while(q--){
        cin>>r>>x>>y;
        if(r==2){
            update(1,1,n,x,y);
        }
        else{
            ll ans=query(1,1,n,x,y);
            cout<<ans<<endl;
        }
    }

    return 0;
}

