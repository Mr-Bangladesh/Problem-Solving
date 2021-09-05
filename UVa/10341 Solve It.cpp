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
int p,q,r,s,t,u;
double f(double x){
    double ans=p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
    return ans;
}

int main()
{
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF){
        if(f(0.0)*f(1.0)>0){
            printf("No solution\n");
            continue;
        }
        double l=0.0000,r=1.0000;
        for(int i=1;i<=50;i++){
            double mid=(l+r)/2.0;
            if(f(mid)>0){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        printf("%.4f\n",l);
    }

    return 0;
}


