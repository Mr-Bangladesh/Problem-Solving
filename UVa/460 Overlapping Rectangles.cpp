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
    int x,y;
    Point(){ x=y=0;}
    Point(int _x,int _y){ x=_x; y=_y; }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        Point a,b,c,d;
        cin>>a.x>>a.y>>b.x>>b.y;
        cin>>c.x>>c.y>>d.x>>d.y;

        Point u,v;
        u.x=max(a.x,c.x);
        u.y=max(a.y,c.y);
        v.x=min(b.x,d.x);
        v.y=min(b.y,d.y);

        if(u.x>=v.x || u.y>=v.y){
            cout<<"No Overlap"<<endl;
        }
        else{
            cout<<u.x<<" "<<u.y<<" "<<v.x<<" "<<v.y<<endl;
        }
        if(t) cout<<endl;
    }

    return 0;
}

