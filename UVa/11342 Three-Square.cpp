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
    vector<ll> v;
    for(ll i=0;i<=225;i++){
        v.pb(i*i);
    }
    vector<ll> cnt[50002];
    for(int i=0;i<v.size();i++){
        ll x=v[i];
        if(x>50000) continue;
        for(int j=i;j<v.size();j++){
            ll y=v[j];
            if(y>50000 || x+y>50000) continue;
            for(int k=j;k<v.size();k++){
                ll z=v[k];
                if(z>50000 || x+y+z>50000) continue;
                ll tmp=x+y+z;
                //cout<<sqrt(v[i])<<" "<<sqrt(v[j])<<" "<<sqrt(v[k])<<" "<<tmp<<endl;
                if(cnt[tmp].size()==0){
                    cnt[tmp].pb(sqrt(x));
                    cnt[tmp].pb(sqrt(y));
                    cnt[tmp].pb(sqrt(z));
                }
            }
        }
    }

    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        if(cnt[n].size()==0) printf("-1\n");
        else printf("%lld %lld %lld\n",cnt[n][0],cnt[n][1],cnt[n][2]);
    }

    return 0;
}

