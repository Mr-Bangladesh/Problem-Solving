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

ll mn,mx,d;
void f(ll digit,ll num){
    //cout<<digit<<" "<<num<<endl;
    if(digit==0){
        //cout<<num<<endl;
        if(num%d==0){
            mn=min(mn,num);
            mx=max(mx,num);
        }
        return;
    }
    f(digit-1,num*10+1);
    f(digit-1,num*10+2);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        ll n,m;
        scanf("%lld %lld",&n,&m);
        d=1<<m;
        mn=INF; mx=-1;
        f(n,0);
        if(mn==INF && mx==-1){
            printf("Case %d: impossible\n",cs);
        }
        else if(mn==mx){
            printf("Case %d: %lld\n",cs,mn);
        }
        else{
            printf("Case %d: %lld %lld\n",cs,mn,mx);
        }
    }

    return 0;
}

