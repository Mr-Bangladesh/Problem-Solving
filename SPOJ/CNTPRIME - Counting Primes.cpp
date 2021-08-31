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

int const MAXX = 1e6 + 1;
bitset<MAXX> prime;
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for(int i = 2; i * i < MAXX; ++i){
        if(prime[i]){
            for(int j = i * i; j < MAXX; j += i)
                prime[j] = 0;
        }
    }
}
int a[10005],tree[50007],prop[50006];
void build(int n,int b,int e){
    if(b==e){
        tree[n]=prime[a[b]];
        return;
    }
    int  mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    tree[n]=tree[n*2]+tree[n*2+1];
    //cout<<b<<" "<<e<<" "<<tree[n]<<endl;
}
void propagate(int n,int b,int e){
    int mid=(b+e)/2;
    int l=n*2; int r=l+1;
    prop[l]=prop[r]=prop[n];
    tree[l]=prime[prop[l]]*(mid-b+1);
    tree[r]=prime[prop[r]]*(e-mid);
    tree[n]=prime[prop[n]]*(e-b+1);
    prop[n]=0;
}
void update(int n,int b,int e,int i,int j,int v){
    if(i>e || j<b) return;
    if(prop[n]){
        propagate(n,b,e);
    }
    if(b>=i && e<=j){
        tree[n]=prime[v]*(e-b+1);
        prop[n]=v;
        return;
    }
    int mid=(b+e)/2;
    update(n*2,b,mid,i,j,v);
    update(n*2+1,mid+1,e,i,j,v);
    tree[n]=tree[n*2]+tree[n*2+1];
}
int query(int n,int b,int e,int i,int j){
    if(e<i || b>j) return 0;
    if(prop[n]){
        propagate(n,b,e);
    }
    if(b>=i && e<=j) return tree[n];
    int mid=(b+e)/2;
    int P1=query(n*2,b,mid,i,j);
    int P2=query(n*2+1,mid+1,e,i,j);
    return P1+P2;
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    int t,n,m,x,y,w,k,q,r,p,cs;
    sieve();

    scanf("%d",&t);
    for(cs=1;cs<=t;cs++){
        scanf("%d %d",&n,&q);
        memset(a,0,sizeof(a));
        memset(tree,0,sizeof(tree));
        memset(prop,0,sizeof(prop));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        while(q--){
            scanf("%d",&p);
            if(!p){
                scanf("%d %d %d",&x,&y,&w);
                update(1,1,n,x,y,w);
            }
            else{
                scanf("%d %d",&x,&y);
                int ans=query(1,1,n,x,y);
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}
