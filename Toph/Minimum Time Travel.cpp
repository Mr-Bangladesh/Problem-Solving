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

struct Point{
    ll x,y;
    Point(){ x=y=0;}
    Point(ll _x,ll _y){ x=_x; y=_y; }
};
ll area(Point a,Point b,Point c){
    ll sum=(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));
    if(sum==0){
        sum=INF;
    }
    return abs(sum);
}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<Point> v;
        ll x,y;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            v.pb(Point(x,y));
        }
        ll ans=INF;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    ans=min(ans,area(v[i],v[j],v[k]));
                }
            }
        }
        double res=(double)ans/2.00;
        printf("%.10f\n",res);
    }

    return 0;
}


