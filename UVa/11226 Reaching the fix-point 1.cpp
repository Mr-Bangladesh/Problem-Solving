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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
vector<ll> Primes;
ll const MAX = 500000;
bitset<MAX> prime;
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for(ll i = 2; i * i < MAX; ++i)
        if(prime[i])
            for(ll j = i * i; j < MAX; j += i)
                prime[j] = 0;
    for(int i=2;i<=MAX;i++){
        if(prime[i]) Primes.pb(i);
    }
}
int dp[500004],tr[500004*4],cnt[500004];
void build(int n,int b,int e){
    if(b==e){
        tr[n]=dp[b];
        return;
    }
    int mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    tr[n]=max(tr[n*2],tr[n*2+1]);
}
int query(int n,int b,int e,int i,int j){
    if(b>j || e<i) return 0;
    if(b>=i && e<=j) return tr[n];
    int mid=(b+e)/2;
    int x=query(n*2,b,mid,i,j);
    int y=query(n*2+1,mid+1,e,i,j);
    return max(x,y);
}
int main()
{
    sieve();
    dp[1]=cnt[1]=1;
    int n=500000;

    for(int x:Primes){
        ll s=1;
        for(int j=1;s<=n;j++){
            s=s*x;
            if(s>n) break;
            for(int i=s;i<=n;i+=s){
                cnt[i]+=x;
            }
        }
    }

    //for(int i=1;i<=25;i++) cout<<i<<" "<<cnt[i]<<endl;

    for(int i=2;i<=n;i++){
        int x=cnt[i];
        if(x==i){
            dp[i]=1;
        }
        else{
            dp[i]=dp[x]+1;
        }
    }
    build(1,1,n);

    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>y) swap(x,y);
        int ans=query(1,1,n,x,y);
        printf("Case #%d:\n%d\n",cs,ans);
    }

    return 0;
}

