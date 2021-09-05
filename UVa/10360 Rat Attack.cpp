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
int a[1026][1026];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int d,n;
        scanf("%d %d",&d,&n);
        int r,c,N=1025,M=1025,k;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&r,&c,&k); r++; c++;
            int left=c-1,right=M-c,up=r-1,down=N-r;
            int mx=min(d,min(left,min(right,min(up,down))));
            int x1=r-mx,y1=c-mx,x2=r+mx,y2=c+mx;
            //cout<<r<<" "<<c<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"  "<<mx<<endl;
            for(int j=x1;j<=x2;j++){
                for(int l=y1;l<=y2;l++){
                    a[j][l]+=k;
                }
            }
        }
        int mx=0,x=1,y=1;
        for(int i=1;i<=1025;i++){
            for(int j=1;j<=1025;j++){
                if(a[i][j]>mx){
                    mx=a[i][j];
                    x=i-1; y=j-1;
                }
            }
        }
        printf("%d %d %d\n",x,y,mx);
    }

    return 0;
}

