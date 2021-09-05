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
    int n,m,cs=1;
    while(scanf("%d %d",&n,&m)!=EOF){
        int a[20]={0};
        int sum=0;
        for(int i=1;i<=m;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a+1,a+2*n+1);

        //for(int i=1;i<=n*2;i++) cout<<a[i]<<" "; cout<<endl;

        double avg=(double)sum/n;
        double ans=0;
        printf("Set #%d\n",cs++);
        for(int i=1;i<=n;i++){
            double x=(double)a[i]+(double)a[2*n-i+1];
            //cout<<avg<<" "<<x<<endl;
            printf(" %d:",i-1);
            if(a[i]!=0) printf(" %d",a[i]);
            if(a[2*n-i+1]!=0) printf(" %d",a[2*n-i+1]);
            printf("\n");
            ans+=abs(x-avg);
        }
        printf("IMBALANCE = %.5f\n",ans);
        printf("\n");
    }

    return 0;
}

