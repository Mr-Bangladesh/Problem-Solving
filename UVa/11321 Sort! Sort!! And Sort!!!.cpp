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
int M;
bool cmp(int a,int b){
    int r1=a%M; int r2=b%M;
    if(r1==r2){
        int x=a%2; int y=b%2;
        if(x==0 && x==y){
            return a<b;
        }
        if(x==1 && x==y){
            return a>b;
        }
        return x>y;
    }
    return r1<r2;
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)){
        printf("%d %d\n",n,m);
        M=m;
        if(n==0 && m==0) break;
        int a[n+1];
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);

        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) cout<<a[i]<<endl;
    }

    return 0;
}

