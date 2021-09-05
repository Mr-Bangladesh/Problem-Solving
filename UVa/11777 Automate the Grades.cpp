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
        int a[7];
        for(int i=0;i<7;i++) scanf("%d",&a[i]);

        sort(a+4,a+7);

        double avg=double(a[6]+a[5])/2.00;
        double sum=avg;
        for(int i=0;i<4;i++){
            sum+=(double(a[i]));
        }

        if(sum>=90.000){
            printf("Case %d: A\n",cs);
        }
        else if(sum>=80.000 && sum<90.000){
            printf("Case %d: B\n",cs);
        }
        else if(sum>=70.000 && sum<80.000){
            printf("Case %d: C\n",cs);
        }
        else if(sum>=60.000 && sum<70.000){
            printf("Case %d: D\n",cs);
        }
        else{
            printf("Case %d: F\n",cs);
        }
    }

    return 0;
}

