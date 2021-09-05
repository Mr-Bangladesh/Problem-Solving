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

ll dp[100005];
vector<ll> v1{0,9,189,2889,38889,488889,5888889};
int prev(int idx){
    int sum=1;
    for(int i=1;i<=idx;i++) sum=sum*10;
    return sum;
}
ll f(ll n){
    if(n<10) return n;
    int d=lower_bound(v1.begin(),v1.end(),n)-v1.begin();
    int x=n-v1[d-1];
    int m=x/d;
    int r=x%d;
    int num=prev(d-1)+m-1;
    if(r) num++;
    if(r==0) r=d;
    vector<int> tmp;
    while(num){
        tmp.pb(num%10);
        num/=10;
    }
    reverse(tmp.begin(),tmp.end());
    return tmp[r-1];
}
int main()
{
    ll len=1;
    vector<ll> v;
    v.pb(0);
    dp[1]=1;
    v.pb(1);
    for(int i=2;i<=100000;i++){
        int x=log10(i);
        dp[i]=dp[i-1]+x+1;
        len+=dp[i];
        v.pb(len);
    }

    ll t;
    scanf("%lld",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll idx=lower_bound(v.begin(),v.end(),n)-v.begin();
        ll cnt=n-v[idx-1];
        printf("%lld\n",f(cnt));
    }

    return 0;
}

