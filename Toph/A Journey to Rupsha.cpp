/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 100005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
///order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll n,q,a[maxn],x,y;
struct ff{
    int val,cnt;
}t[maxn*4];
ll cur,res;
ll bigmod(ll B,ll P,ll M){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=bigmod(B,P/2,M);
        return ((R%M)*(R%M))%M;
    }
    else{
        ll R=bigmod(B,P-1,M);
        return ((R%M)*(B%M))%M;
    }
}
void update(int n,int b,int e,int i,int j){
    if(b>j || e<i) return;
    if(b>=i && e<=j){
        t[n].val+=cur;
        t[n].cnt++;
        cur+=(e-b+1);
        return;
    }
    int mid=(b+e)/2;
    update(n*2,b,mid,i,j);
    update(n*2+1,mid+1,e,i,j);
}
void query(int n,int b,int e,int i){
    if(b>i || e<i) return;
    if(i>=b && i<=e){
        res+=t[n].val;
        ll x=i-b;
        //cout<<res<<" "<<x<<" "<<t[n].cnt<<endl;
        x*=t[n].cnt;
        res+=x;
        //cout<<res<<" "<<t[n].val<<" "<<t[n].cnt<<" "<<i-b<<endl;
    }
    if(b==e) return;
    int mid=(b+e)/2;
    query(n*2,b,mid,i);
    query(n*2+1,mid+1,e,i);
}
int main()
{
    scanf("%lld %lld",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]%=MOD;
    }
    char s[30];
    while(q--){
        scanf("%s",s);
        if(s[0]=='M'){
            scanf("%lld %lld",&x,&y);
            cur=0;
            update(1,1,n,x,y);
        }
        else{
            scanf("%lld",&x);
            res=0;
            query(1,1,n,x);
            ll ans=bigmod(3,res,MOD);
            //cout<<x<<" "<<ans<<" "<<res<<endl;
            ans=(ans*a[x])%MOD;
            printf("%lld\n",ans);
        }
    }

    return 0;
}


