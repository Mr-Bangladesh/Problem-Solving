/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI acos(-1.0)
#define EPS 1e-9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

double todeg(double theta){
    return (theta*180.0)/PI;
}
int main()
{
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        double r,ab;
        cin>>r>>ab;
        r*=2.0;
        double theta=asin(ab/r);
        theta=2.0*todeg(theta);
        theta=180.0-theta;
        theta/=2.0;
        printf("Case %d: %.4f\n",cs,theta);
    }

    return 0;
}


