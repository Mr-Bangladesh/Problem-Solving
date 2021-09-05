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

int n,m,k;
ll dp[22][22];
struct ff{
	int a,b,c;
	ff(int _a,int _b,int _c){
		a=_a; b=_b; c=_c;
	}
};
//map<ff,ll> dp;
ll f(int a,int b,int c){
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(b==0 && c==0){
		return 1;
	}
	if(a<=0) return 0;
	if(b<=0 && c<=0) return 0;
	//if(dp.find(ff(a,b,c))!=dp.end()) return dp[ff(a,b,c)];
	//if(dp[b][c]!=-1) return dp[b][c];
	
	ll w,x,y,z;
	w=x=y=z=0;
	
	if(a>0 && b>0) w=f(a-1,b-1,c);
	if(a>0 && b>1) x=f(a-1,b-2,c);
	if(a>0 && c>0) y=f(a-1,b,c-1);
	if(a>0 && c>1) z=f(a-1,b,c-2);
	
	//cout<<a<<" "<<b<<" "<<c<<" "<<x<<" "<<z<<endl;
	
	//return dp[ff(a,b,c)]=w+x+y+z;
	return w+x+y+z;
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	
	//memset(dp,-1,sizeof(dp));
	
	ll ans=f(n,m,k);
	
	printf("%lld\n",ans);
	

    return 0;
}

