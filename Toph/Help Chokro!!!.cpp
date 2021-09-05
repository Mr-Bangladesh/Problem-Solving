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
#define EPS 1e-9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

ll f(ll a[],int n,ll x){
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=abs(a[i]-x);
    }
    return sum;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    ll l=0,r=1e6;
    while(r-l>=3){
        ll mid1=l+(r-l)/3;
        ll mid2=r-(r-l)/3;
        ll x=f(a,n,mid1*k);
        ll y=f(a,n,mid2*k);
        //cout<<mid1<<" "<<x<<" "<<mid2<<" "<<y<<endl;
        if(x>y){
            l=mid1+1;
        }
        else{
            r=mid2-1;
        }
    }

    //cout<<l<<" "<<r<<endl;

    ll mn=INF;
    for(ll i=l;i<=r;i++){
        mn=min(mn,f(a,n,i*k));
    }
    cout<<mn<<endl;

    return 0;
}


