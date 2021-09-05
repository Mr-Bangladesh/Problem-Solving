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
ll mark[8000005];
struct ff{
    ll a,b,c,d;
    ff(ll i,ll j,ll k,ll l){
        a=i; b=j; c=k; d=l;
    }
};
bool cmp(ff a,ff b){
    if(a.a==b.a){
        if(a.b==b.b){
            if(a.c==b.c) return a.d<b.d;
            return a.c<b.c;
        }
        return a.b<b.b;
    }
    return a.a<b.a;
}
int main()
{
    for(int i=1;i<=200;i++){
        mark[i*i*i]=i;
    }
    vector<ff> ans;
    for(ll i=2;i<=200;i++){
        for(ll j=i+1;j<=200;j++){
            for(ll k=j+1;k<=200;k++){
                ll x=i*i*i + j*j*j + k*k*k;
                if(x>8000000) continue;
                if(mark[x]){
                    ans.pb(ff(mark[x],i,j,k));
                }
            }
        }
    }

    sort(ans.begin(),ans.end(),cmp);

    for(ff x:ans){
        printf("Cube = %lld, Triple = (%lld,%lld,%lld)\n",x.a,x.b,x.c,x.d);
    }

    return 0;
}

