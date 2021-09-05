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

ll cost(ll x){
    ll sum=0;
    sum+=(2*min(100,x));
    x-=min(100,x);
    sum+=(3*min(9900,x));
    x-=min(9900,x);
    sum+=(5*min(990000,x));
    x-=min(990000,x);
    sum+=(7*x);
    return sum;
}

int main()
{
    ll cwh,gap;
    while(scanf("%lld %lld",&cwh,&gap),cwh||gap){
        ll l=1,r=cwh;
        ll total=0;
        while(l<r){
            ll mid=(l+r)/2; //cout<<l<<" "<<r<<" "<<mid<<endl;
            ll x=cost(mid);
            if(x==cwh){
                total=mid;
                break;
            }
            if(x<cwh){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        cout<<total<<endl;
        ll ans=0;
        l=1; r=total;
        while(l<r){
            ll mid=(l+r)/2;
            ll x=cost(mid);
            ll y=cost(total-mid);
            cout<<mid<<" "<<total-mid<<" "<<x<<" "<<y<<endl;
            if(x+y==cwh){
                cout<<mid<<" "<<x<<" "<<y<<endl;
            }
            if(x+y<cwh){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
//            if(y-x==gap){
//                ans=mid; break;
//            }
//            if(x>y){
//                r=mid-1;
//            }
//            else{
//                l=mid+1;
//            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

