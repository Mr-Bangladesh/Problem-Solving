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
    //getchar();
    for(int cs=1;cs<=t;cs++){
        char ch; int n; getchar();
        scanf("%c = %d",&ch,&n);
        //cout<<ch<<" "<<n<<endl;
        int a[n+2][n+2];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int v[n+2],x=n;
        for(int i=1;i<=n;i++){
            v[i]=x;
            x--;
        }
        bool check=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x=v[i],y=v[j];
                if(a[i][j]!=a[x][y]){
                    check=false; break;
                }
            }
            if(check) break;
        }
        if(check){
            printf("Test #%d: Symmetric.\n",cs);
        }
        else{
            printf("Test #%d: Non-symmetric.\n",cs);
        }
    }

    return 0;
}

