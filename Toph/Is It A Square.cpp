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
vector<ll> Primes;
ll const MAX = 320;
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
struct ab{
    map<int,int> freq;
    vector<int> pr;
};
ab dp[100005];
void init(int n){
    int m=n;
    for(int i=0;Primes[i]*Primes[i]<=n;i++){
        if(n%Primes[i]) continue;
        int c=0;
        while(n%Primes[i]==0){
            c++;
            n/=Primes[i];
        }
        dp[m].freq[Primes[i]]=c;
        dp[m].pr.pb(Primes[i]);
    }
    if(n!=1){
        dp[m].freq[n]=1;
        dp[m].pr.pb(n);
    }
}
struct ff{
    int l,r,idx;
    ff(int a,int b,int c){
        l=a; r=b; idx=c;
    }
};
int K;
bool comp(ff a,ff b){
    if(a.l/K==b.l/K) return a.r<b.r;
    return a.l/K<b.l/K;
}
int cnt[100005];
int odd=0;
int neg=0,zero=0;
void add(int n){
    if(n==0){
        zero++;
        return;
    }
    if(n<0){
        neg++;
        n=n*(-1);
    }

    for(int u:dp[n].pr){
        int x=cnt[u];
        cnt[u]+=dp[n].freq[u];
        if(x){
            if(x%2==0 && cnt[u]%2==1) odd++;
            if(x%2==1 && cnt[u]%2==0) odd--;
        }
        else{
            if(cnt[u]%2) odd++;
        }
    }
}
void del(int n){
    if(n==0){
        zero--;
        return;
    }
    if(n<0){
        neg--;
        n=n*(-1);
    }

    for(int u:dp[n].pr){
        int x=cnt[u];
        cnt[u]-=dp[n].freq[u];
        if(cnt[u]){
            if(x%2==0 && cnt[u]%2==1) odd++;
            if(x%2==1 && cnt[u]%2==0) odd--;
        }
        else{
            if(x%2) odd--;
        }
    }
}
bool query(){
    if(odd) return false;
    return true;
}
int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    int t,n,m,x,y,w,k,q,p,cs;

    sieve();

    for(int i=2;i<=100000;i++){
        init(i);
    }

    scanf("%d %d",&n,&q);
    K=sqrt(n);
    int a[n+2];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    vector<ff> v;
    for(int i=1;i<=q;i++){
        scanf("%d %d",&x,&y);
        v.pb(ff(x,y,i));
    }
    sort(v.begin(),v.end(),comp);

    int ans[q+3]={0};
    int l=1,r=0;
    for(ff it:v){
        int l1=it.l; ll r1=it.r; ll idx=it.idx;
        while(r<r1){
            r++;
            add(a[r]);
        }
        while(r>r1){
            del(a[r]);
            r--;
        }
        while(l<l1){
            del(a[l]);
            l++;
        }
        while(l>l1){
            l--;
            add(a[l]);
        }
        if(zero){
            ans[idx]=1;
            continue;
        }
        if(neg%2){
            ans[idx]=0;
            continue;
        }
        ans[idx]=query();
    }

    for(int i=1;i<=q;i++){
        if(ans[i]) cout<<"Yes";
        else cout<<"No";
        if(i!=q) cout<<endl;
    }

    return 0;
}
