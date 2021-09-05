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
int n,sum,a[45],b[45],dp[42][305][305];
int f(int idx,int x,int y){
    int m=sum*sum-(x*x+y*y);
    //cout<<idx<<" "<<x<<" "<<y<<" "<<m<<endl;
    if(m==0) return 0;
    if(m<0 || idx>=n) return 1e5;
    if(dp[idx][x][y]!=-1) return dp[idx][x][y];
    int r1=1e5,r2=1e5;
    r1=1+f(idx,x+a[idx],y+b[idx]);
    r2=f(idx+1,x,y);
    return dp[idx][x][y]=min(r1,r2);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&sum);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i],&b[i]);
        }
        memset(dp,-1,sizeof(dp));
        int ans=f(1,0,0);
        if(ans>=1e5){
            printf("not possible\n");
        }
        else{
            printf("%d\n",ans);
        }
    }

    return 0;
}

