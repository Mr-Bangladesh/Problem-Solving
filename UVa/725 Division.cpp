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
    int n,first=0;
    while(scanf("%d",&n),n){
        if(first){
            printf("\n");
        }
        first=1;
        bool check=false;
        for(int i=1234;i<=98765;i++){
            int j=i*n;
            if(j>99999) continue;
            set<int> s;
            if(i<10000){
                s.insert(0);
            }
            int x=i,y=j;
            while(x){
                s.insert(x%10);
                x/=10;
            }
            while(y){
                s.insert(y%10);
                y/=10;
            }
            if(s.size()==10){
                printf("%.5d / %.5d = %d\n",j,i,n);
                check=true;
            }
        }
        if(!check){
            printf("There are no solutions for %d.\n",n);
        }
    }

    return 0;
}

