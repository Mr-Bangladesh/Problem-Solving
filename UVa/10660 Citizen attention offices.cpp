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
struct ff{
    int r,c,p;
    ff(int a,int b,int d){
        r=a;c=b; p=d;
    }
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<ff> v;
        for(int i=1;i<=n;i++){
            int x,y,k;
            scanf("%d %d %d",&x,&y,&k);
            v.pb(ff(x,y,k));
        }
        int ans=INT_MAX;
        vector<int> res;
        for(int i=0;i<25;i++){
            for(int j=i+1;j<25;j++){
                for(int k=j+1;k<25;k++){
                    for(int l=k+1;l<25;l++){
                        for(int m=l+1;m<25;m++){
                            int total=0;
                            for(ff inp:v){
                                int mncost=INT_MAX;
                                for(int of:{i,j,k,l,m}){
                                    int x=of/5,y=of%5;
                                    mncost=min(mncost,abs(inp.r-x)+abs(inp.c-y));
                                }
                                total+=(mncost*inp.p);
                            }
                            if(total<ans){
                                ans=total;
                                res={i,j,k,l,m};
                            }
                        }
                    }
                }
            }
        }
        printf("%d %d %d %d %d\n",res[0],res[1],res[2],res[3],res[4]);
    }

    return 0;
}

