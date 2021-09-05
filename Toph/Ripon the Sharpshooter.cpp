/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

ll n, A[12];

ll calc(int id, int mask){
    if(id == n)return 0;
    ll ret = 0;
    ll Max = 0;
    
    for(int i = 0; i < n; i++){
        if(mask &(1 << i))continue;
        ll l = 1, r = 1; 
        for(int j = i - 1; j >= 0; j--){
            if(mask &(1 << j))continue;
            l = A[j]; break;
        }
        for(int j = i + 1; j < n; j++){
            if(mask & (1 << j))continue;
            r = A[j]; break;
        }
        ret = l * r;
        if(l ==1 and r == 1)ret = 0;
        ret = ret + calc(i + 1, mask | (1 << i));
        Max = max(ret, Max);
    }
    return Max;
}

int main(){
	
    while(scanf("%lld", &n)!=EOF){
	    for(int i = 0; i < n; i++){
	        scanf("%lld", &A[i]);
	    }
	    printf("%lld\n", calc(0,0));
    }
    
}

