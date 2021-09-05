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

int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y)){
        if(x==1 && y==1) break;
        int l1=0,l2=1,r1=1,r2=0,m1=1,m2=1;
        string ans="";
        while(m1!=x || m2!=y){
            int left=m2*x; int right=m1*y;
            if(left<right){
                r1=m1;r2=m2;
                m1=m1+l1; m2=m2+l2;
                ans+='L';
            }
            else{
                l1=m1; l2=m2;
                m1=m1+r1; m2=m2+r2;
                ans+='R';
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

