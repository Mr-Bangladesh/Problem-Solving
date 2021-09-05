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
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        bool check=false;
        for(int i=1;i<=100;i++){
            for(int j=i+1;j<=100;j++){
                for(int k=j+1;k<=100;k++){
                    int x=i+j+k;
                    int y=i*j*k;
                    int z=i*i+j*j+k*k;
                    if(x==a && y==b && z==c){
                        printf("%d %d %d\n",i,j,k);
                        check=true;
                        break;
                    }
                }
                if(check) break;
            }
            if(check) break;
        }
        if(!check){
            printf("No solution.\n");
        }
    }

    return 0;
}
