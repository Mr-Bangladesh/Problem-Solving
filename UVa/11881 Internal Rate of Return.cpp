/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS 1e-9
#define PI 2*acos(0.0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
int cf[100];
double f(int t,double irr){
    double sum=(double)cf[0];
    double p=1.00;
    for(int i=1;i<=t;i++){
        p=p*(1.00+irr);
        double x=(double)cf[i]/p;
        //cout<<i<<" "<<p<<" "<<1.00+irr<<" "<<x<<endl;
        sum+=x;
    }
    return sum;
}

int main()
{
    int t;
    while(scanf("%d",&t),t){
        for(int i=0;i<=t;i++){
            scanf("%d",&cf[i]);
        }
        double l=-0.99999999,r=10000.00;
        double ans=0;
        for(int i=1;i<=50;i++){
            double mid=(l+r)/2.0;
            double x=f(t,mid);
            //cout<<l<<" "<<r<<" "<<mid<<" "<<x<<" "<<abs(x-0.000000)<<endl;
            if(abs(x-0.000000)<=EPS){
                ans=mid;
                //cout<<mid<<endl;
                break;
            }
            else if(x<0){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        printf("%.2f\n",ans);
    }

    return 0;
}

