// Problem: Paying Bills
// Contest: Toph
// URL: https://toph.co/p/paying-bills
// Memory Limit: 1024 MB
// Time Limit: 15000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

vector<int> g[1005];
int dp[16][1<<16];
int n,m;
bool check(int a,int b){
	for(int i=0;i<n;i++){
		if((a&(1<<i)) && (b&(1<<i))) return false;
	}
	return true;
}
int b[20];
int f(int idx,int mask){
	if(idx==0){
		int x=__builtin_popcount(mask);
		return x;
	}
	int &ret=dp[idx][mask];
	if(ret!=-1) return ret;
	ret=INT_MAX;
	for(int x:g[b[idx]]){
		if(check(mask,x)){
			ret=min(ret,f(idx-1,mask|x));
		}
	}
	return ret;
}

int main()
{
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		scanf("%d",&m);
		int mark[2000]={0};
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			mark[b[i]]=1;
		}
			
			for(int mask=0;mask<(1<<n);mask++){
				int sum=0;
				for(int j=0;j<n;j++){
					if(mask&(1<<j)){
						sum+=a[j];
					}
				}
				if(sum<=1000 && mark[sum]){
					g[sum].pb(mask);
				}
		    }
		
		// for(int i=1;i<=m;i++){
			// cout<<b[i]<<"  ";
			// for(int x:g[b[i]]) cout<<x<<" ";cout<<endl;
		// }
		
		memset(dp,-1,sizeof(dp));
		
		int ans=f(m,0); if(ans==INT_MAX) ans=-1;
		
		printf("Case %d: %d\n",cs++,ans);
		
		for(int i=1;i<=1000;i++) g[i].clear();
		
	}

    return 0;
}

