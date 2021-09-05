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
int n,x[20],y[20],target;
double dist[20][20];
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
double dp[(1<<17)];
double f(int mask){
    //cout<<mask<<endl;
    if(mask==target) return 0.00;
    if(dp[mask]>-1.0) return dp[mask];
    double ans=1000000000.00;
    int u,v;
    for(u=1;u<=n*2;u++){
        if(!check(mask,u)) break;
    }
    for(v=u+1;v<=n*2;v++){
        if(!check(mask,v)){

            ans=min(ans,dist[u][v]+f(Set(mask,u)|Set(mask,v)));
            //cout<<u<<" "<<v<<" "<<dist[u][v]<<" "<<ans<<endl;
        }
    }
    return dp[mask]=ans;
}
int main()
{
    int cs=1;
    while(scanf("%d",&n),n){
        char s[100];
        for(int i=1;i<=n*2;i++){
            scanf("%s %d %d",s,&x[i],&y[i]);
        }
        for(int i=1;i<=n*2;i++){
            for(int j=i+1;j<=n*2;j++){
                dist[i][j]=dist[j][i]=hypot(x[i]-x[j],y[i]-y[j]);
                //cout<<i<<" "<<j<<" "<<dist[i][j]<<endl;
            }
        }
        target=(1<<(n*2+1))-1;
        for(int i=0;i<=target;i++) dp[i]=-1.0;
        double ans=f(1);
        printf("Case %d: %.2f\n",cs++,ans);
        //cout<<target<<endl;
    }

    return 0;
}

