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

int main()
{
    int x;
    int cs=1;
    while(scanf("%d",&x)){
        if(x==-1) break;
        vector<int> v;
        v.pb(0);
        v.pb(x);
        while(scanf("%d",&x)){
            if(x==-1) break;
            v.pb(x);
        }
        //for(int i:v) cout<<i<<" "; cout<<endl;
        int n=v.size()-1;
        int L[n+2]={0},LIS=1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(v[j]<=v[i]){
                    if(L[j]<L[i]+1){
                        L[j]=L[i]+1;
                        LIS=max(LIS,L[j]+1);
                    }
                }
            }
        }
        if(cs!=1) printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n",cs++,LIS);
    }

    return 0;
}


