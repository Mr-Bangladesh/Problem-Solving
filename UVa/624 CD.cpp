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
ll cap,a[22],res,mx,m;
void f(int idx,ll sum,ll mask){
    //cout<<idx<<" "<<sum<<endl;
    if(idx>m || sum>cap) return;
    //if(sum==55) cout<<idx<<" "<<sum<<" "<<mask<<endl;
    if(sum>mx){
        mx=sum;
        res=mask;
    }
    if(idx>=m) return;
    if(sum+a[idx]<=cap){
        f(idx+1,sum+a[idx],mask|(1<<idx));
    }
    f(idx+1,sum,mask);
}

int main()
{
    ll n;
    while(scanf("%lld",&n)!=EOF){
        cap=n;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%lld",&a[i]);
        }
        res=0;mx=-1;
        f(0,0,0);
        //cout<<res<<endl;
        for(ll i=0;i<m;i++){
            if(res&(1<<i)){
                printf("%lld ",a[i]);
            }
        }
        printf("sum:%lld\n",mx);
        //cout<<res<<" "<<mx<<endl;
    }

    return 0;
}

