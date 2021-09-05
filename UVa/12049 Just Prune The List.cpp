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

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,m,x,ans;
        scanf("%lld %lld",&n,&m);
        map<ll,ll> cnt1,cnt2;
        ans=0;
        set<ll> s;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x);
            cnt1[x]++;
            s.insert(x);
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&x);
            cnt2[x]++;
            s.insert(x);
        }
        for(auto it:s){
            ll d=min(cnt1[it],cnt2[it]);
            //cout<<it<<" "<<cnt1[it]<<" "<<cnt2[it]<<endl;
            ans+=d;
        }
        printf("%lld\n",n+m-ans*2);
    }

    return 0;
}

