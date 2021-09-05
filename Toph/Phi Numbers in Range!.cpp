#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

const ll maxx=1000000;
int status[(maxx>>5)+2];

bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N, int pos)
{
    return N=(N|(1<<pos));
}
vector<ll>Primes;
void sieve()
{
    ll i,j,sqrtN;
    sqrtN=ll(sqrt(maxx))+1;
    Primes.pb(2);
    for(int i=3;i<=maxx;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            Primes.pb(i);

            if(i<=sqrtN)
            for(j=i*i;j<=maxx;j+=(i<<1))
            {
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
}

ll lim=100000;
ll A[100008];
void F()
{
    for(ll i=1;i<=lim;i++) A[i]=i;

    ll x=Primes.size();

    for(ll i=0;i<x;i++)
    {
        ll U=Primes[i];

        for(ll j=U;j<=lim;j+=U)
        {
            A[j]=(A[j]*(U-1))/U;
        }
    }
}
struct ff{
    ll l,r,k,idx;
    ff(ll a,ll b,ll c,ll d){
        l=a; r=b; k=c; idx=d;
    }
};
ll K;
bool cmp(ff a,ff b){
    ll a1=a.l/K; ll b1=b.l/K;
    if(a1==b1) return a.r<b.r;
    return a1<b1;
}
ll tree[500005];
void update(ll n,ll b,ll e,ll i,ll v){
    if(b==e){
        tree[n]=v;
        return;
    }
    ll mid=(b+e)/2;
    if(mid>=i){
        update(n*2,b,mid,i,v);
    }
    else{
        update(n*2+1,mid+1,e,i,v);
    }
    tree[n]=tree[n*2]+tree[n*2+1];
    //cout<<n<<" "<<b<<" "<<e<<" "<<tree[n]<<" "<<tree[n*2]<<" "<<tree[n*2+1]<<endl;
}
ll query(ll n,ll b,ll e,ll k){
    //cout<<"query "<<n<<" "<<b<<" "<<e<<" "<<k<<endl;
    if(b==e){
        return b;
    }
    ll mid=(b+e)/2;
    if(tree[n*2]>=k){
        return query(n*2,b,mid,k);
    }
    else{
        return query(n*2+1,mid+1,e,k-tree[n*2]);
    }
}
ll cnt[100005];
ll sum=0;
void add(ll x,ll n){
    cnt[x]++;
    if(cnt[x]==1){
        sum++; //cout<<"added "<<x<<endl;
        update(1,1,n,x,1);
    }
}
void del(ll x,ll n){
    cnt[x]--;
    if(cnt[x]==0){
        sum--; //cout<<"deleted "<<x<<endl;
        update(1,1,n,x,0);
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    sieve();
    F();
    cin>>t;
    for(cs=1;cs<=t;cs++){
        printf("Case %lld:\n",cs);
        cin>>n>>q;
        K=sqrt(n);
        vector<ff> v;
        for(int i=1;i<=q;i++){
            cin>>x>>y>>k;
            v.pb(ff(x,y,k,i));
        }
        sort(v.begin(),v.end(),cmp);
        ll ans[q+3]={0};
        ll l=1,r=0;
        for(ff it:v){
            ll l1=it.l; ll r1=it.r; ll k1=it.k; ll idx=it.idx;
            while(r<r1){
                r++;
                add(A[r],n);
            }
            while(r>r1){
                del(A[r],n);
                r--;
            }
            while(l<l1){
                del(A[l],n);
                l++;
            }
            while(l>l1){
                l--;
                add(A[l],n);
            }
            //cout<<l1<<" "<<r1<<" "<<sum<<" "<<query(1,1,n,k1)<<endl;
//            for(int z=1;z<=25;z++){
//                cout<<"node "<<z<<" "<<tree[z]<<endl;
//            }
            if(sum<k1) ans[idx]=-1;
            else ans[idx]=query(1,1,n,k1);
        }
        for(int i=1;i<=q;i++){
            if(ans[i]==-1) cout<<"No Distinct Phi Number"<<endl;
            else cout<<ans[i]<<endl;
        }

        memset(tree,0,sizeof(tree));
        memset(cnt,0,sizeof(cnt));
        sum=0;
    }

    return 0;
}
