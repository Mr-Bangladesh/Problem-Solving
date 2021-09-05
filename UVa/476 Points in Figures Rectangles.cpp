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
    double x,y;
    Point(){ x=y=0;}
    Point(int _x,int _y){ x=_x; y=_y;}
    bool operator<(Point other) const{
        if(fabs(x-other.x)>EPS) return x<other.x;
        return y<other.y;
    }
    bool operator == (Point other) const{
        return (fabs(x-other.x)<EPS && fabs(y-other.y)<EPS);
    }
};
bool check(pair<Point,Point> rec,Point p){
    Point u=rec.first,v=rec.second;
    Point a,b;
    a.x=min(u.x,v.x); a.y=min(u.y,v.y);
    b.x=max(u.x,v.x); b.y=max(u.y,v.y);
    if(p.x>a.x && p.y>a.y && p.x<b.x && p.y<b.y){
        return true;
    }
    return false;
}
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    char c;
    vector< pair<Point,Point> > rec;
    while(cin>>c){
        if(c=='*') break;
        Point a,b;
        cin>>a.x>>a.y>>b.x>>b.y;
        rec.pb(mp(a,b));
    }
    Point a;
    int p=1;
    while(cin>>a.x>>a.y){
        if(a.x==9999.9 && a.y==9999.9) break;
        int r=1;
        bool found=false;
        for(auto it:rec){
            if(check(it,a)){
                cout<<"Point "<<p<<" is contained in figure "<<r<<endl;
                found=true;
            }
            r++;
        }
        if(!found){
            cout<<"Point "<<p<<" is not contained in any figure"<<endl;
        }
        p++;
    }

    return 0;
}


