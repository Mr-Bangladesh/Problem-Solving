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

struct ff{
    int x,y,h;
    ff(int a,int b,int c){
        x=a; y =b; h=c;
    }
};
bool cmp(ff a,ff b){
    if(a.x==b.x) return a.y>b.y;
    return a.x>b.x;
}
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int n,x,y,z;
    int cs=1;
    while(scanf("%d",&n),n){
        vector<ff> v;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&x,&y,&z);
            v.pb(ff(x,y,z));
            v.pb(ff(x,z,y));
            v.pb(ff(y,x,z));
            v.pb(ff(y,z,x));
            v.pb(ff(z,x,y));
            v.pb(ff(z,y,x));
        }
        int len=v.size();
        int dp[len+2]={0},ans=0;
        sort(v.begin(),v.end(),cmp);
//        for(auto it:v){
//            cout<<it.x<<" "<<it.y<<" "<<it.h<<endl;
//        }
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){

                if(v[j].x>v[i].x && v[j].y>v[i].y){
                    //cout<<v[i].x<<" "<<v[i].y<<" "<<v[j].x<<" "<<v[j].y<<endl;
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            //cout<<i<<" "<<dp[i]<<endl;
            dp[i]+=v[i].h;
            ans=max(ans,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",cs++,ans);

    }

    return 0;
}


