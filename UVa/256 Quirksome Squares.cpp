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
map<int,vector<int> > ans;
void f(int digit){
    int half=ceil(pow(10,digit/2));
    for(int i=0;i<half;i++){
        int x=i*i;
        int left=x/half; int right=x%half;
        int d=(left+right); d=d*d;
        if(d==x){
            ans[digit].pb(x);
        }
    }
}
int main()
{
    int n;
    f(2); f(4); f(6); f(8);

    while(scanf("%d",&n)!=EOF){
        for(int x:ans[n]){
            printf("%.*d\n",n,x);
        }
    }

    return 0;
}

