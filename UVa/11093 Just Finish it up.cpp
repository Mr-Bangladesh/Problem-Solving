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
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        int a[n+2],b[n+2],sum[n+2],minn[n+2];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            sum[i]=sum[i-1]+a[i]-b[i];
        }
        minn[n]=sum[n];
        for(int i=n-1;i>=1;i--){
            minn[i]=min(sum[i],minn[i+1]);
        }
        int idx=-1;
        for(int i=1;i<=n;i++){
            if(a[i]<b[i]) continue;
            int bck=sum[i-1];
            int mn=minn[i];
            //cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<bck<<" "<<mn<<endl;
            if(mn-bck<0) continue;
            if(sum[n]>=0){
                idx=i; break;
            }
//            if(mn-bck>=0){
//                idx=i; break;
//            }
        }
        if(idx==-1){
            printf("Case %d: Not possible\n",cs);
        }
        else{
            printf("Case %d: Possible from station %d\n",cs,idx);
        }
    }

    return 0;
}

