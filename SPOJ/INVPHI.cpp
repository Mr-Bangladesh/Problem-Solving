// Problem: Smallest Inverse Euler Totient Function
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/INVPHI/
// Memory Limit: 1536 MB
// Time Limit: 20000 ms
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
#define maxn 100000001
#define maxm 202918035
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}


#define MAXN 100000000
#define MAXM 202918035

int phi[maxm+1],res[maxn];

void totient(){
	for(int i=1;i<=maxm;i++) phi[i]=i;
	for(int i=2;i<=maxm;i++){
		if(phi[i]==i){
			for(int j=i;j<=maxm;j+=i){
				//phi[j]-=(phi[j]/i);
				phi[j]=(phi[j]/i)*(i-1);
				//both are correct
			}
		}
	}
	
}

int main()
{
	totient();
	
	for(int i=1;i<=maxm;i++){
		if(phi[i]<maxn && res[phi[i]]==0){
			res[phi[i]]=i;
		}
	}
	
	int t;
	scanf("%d",&t);
	
	while(t--){
		int n;
		scanf("%d",&n);
		int ans=res[n];
		if(ans==0)  ans=-1;
		printf("%d\n",ans);
	}

    return 0;
}

