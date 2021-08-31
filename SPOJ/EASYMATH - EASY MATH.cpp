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
ull _lcm(ull a,ull b){
    ull x=__gcd(a,b);
    return (a*b)/x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ull n,m,a,d;
        scanf("%llu %llu %llu %llu",&n,&m,&a,&d);
        vector<ull> v;
        for(int i=0;i<5;i++){
            ull x=a+d*i;
            v.pb(x);
        }
        ull cnt=m-n+1;
        for(int mask=1;mask<=31;mask++){
            int freq=0;
            ull lcm=1;
            for(int j=0;j<5;j++){
                if(mask&(1<<j)){
                    freq++;
                    lcm=_lcm(lcm,v[j]);
                }
            }
            ull l=n/lcm; if(n%lcm) l++;
            ull r=m/lcm;
            if(freq%2){
                cnt-=(r-l+1);
            }
            else{
                cnt+=(r-l+1);
            }
        }
        printf("%llu\n",cnt);
    }

    return 0;
}


