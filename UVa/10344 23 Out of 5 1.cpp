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
int a[5],v[5],mark[5];
bool ans;
void backtrack(int idx,int sum){
    if(idx==5){
        if(sum==23){
            ans=true;
            return;
        }
    }
    for(int i=0;i<5;i++){
        if(!mark[i]){
            mark[i]=1;
            v[idx]=a[i];
            int x,y,z; x=y=z=0;
            backtrack(idx+1,sum+a[i]);
            if(idx!=0) backtrack(idx+1,sum-a[i]);
            if(idx!=0) backtrack(idx+1,sum*a[i]);
            mark[i]=false;
        }
    }
}
int main()
{
    while(1){
        int x=0;
        for(int i=0;i<5;i++){
            scanf("%d",&a[i]);
            x+=a[i];
        }
        if(!x) break;
        ans=false;
        backtrack(0,0);
        if(ans){
            printf("Possible\n");
        }
        else{
            printf("Impossible\n");
        }
    }

    return 0;
}

