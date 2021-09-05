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
int n;
stack<int> st[55];
bool square(int x){
    int y=sqrt(x);
    return y*y==x;
}
int ans;
void f(int v){
    for(int i=1;i<=n;i++){
        if(st[i].empty()){
            st[i].push(v);
            ans=max(ans,v);
            f(v+1);
        }
        else{
            int u=st[i].top();
            if(square(u+v)){
                st[i].push(v);
                ans=max(ans,v);
                f(v+1);
            }
        }
    }
}
int main()
{
    ans=0;
    int pre[55]={0};
    for(int i=1;i<=50;i++){
        n=i;
        f(ans+1);
        pre[i]=ans;
    }

    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        printf("%d\n",pre[x]);
    }



    return 0;
}

