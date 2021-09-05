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
struct ff{
    int x,y,z;
    ff(int a,int b,int c){
        x=a;y=b; z=c;
    }
};
int main()
{
    int n;
    while(scanf("%d",&n),n){
        ll a[n+2];
        ll mn=INT_MAX;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            mn=min(mn,a[i]);
        }
        if(n<4){
            printf("no solution\n");
            continue;
        }
        set<ll> s;
        for(int i=1;i<=n;i++){
            s.insert(a[i]);
        }
        vector<ll> v;
        for(auto it:s) v.pb(it);
        n=v.size();
        bool check=false;
        //int cnt=0;
        for(int i=n-1;i>=0 && !check;i--){
            for(int j=i-1;j>=0 && !check;j--){
                for(int k=j-1;k>=0 && !check;k--){
                    ll x=v[i]-v[j]-v[k]; //cnt++; cout<<i<<" "<<j<<" "<<k<<endl;
                    if(x==v[i] || x==v[j] || x==v[k]) continue;
                    if(binary_search(v.begin(),v.end(),x)){
                        printf("%lld\n",v[i]);
                        check=true;
                    }
                }
            }
        }
        //cout<<cnt<<endl;
        if(!check){
            printf("no solution\n");
        }
    }

    return 0;
}


