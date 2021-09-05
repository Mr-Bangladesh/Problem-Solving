// Problem: Unbelievable Array
// Contest: Toph
// URL: https://toph.co/p/unbelievable-array
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
int par[maxn],curid[maxn];
set<int> idx[maxn];
void init(int n){
	for(int i=1;i<=n;i++){
		curid[i]=par[i]=i;
		idx[i].clear();
	}
}
int Find(int r){
	if(r==par[r]) return r;
	return par[r]=Find(par[r]);
}
int main()
{
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		int n,q;
		scanf("%d %d",&n,&q);
		init(n);
		int a[n+1];
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			idx[a[i]].insert(i);
			par[i]=a[i];
		}
		int x,y,k;
		printf("Case %d:\n",cs++);
		while(q--){
			scanf("%d",&k);
			if(k==1){
				scanf("%d %d",&x,&y);
				//cout<<x<<" "<<curid[x]<<" "<<y<<" "<<curid[y]<<endl;
				if(idx[curid[x]].size()>idx[curid[y]].size()){
					swap(curid[x],curid[y]);
				}
				
				
				
				for(int i:idx[curid[x]]){
					idx[curid[y]].insert(i);
					//cout<<curid[x]<<" to "<<" "<<curid[y]<<endl; 
					par[i]=curid[y];
				}
				idx[curid[x]].clear();
				//cout<<x<<" "<<curid[x]<<" "<<y<<" "<<curid[y]<<endl;
				//curid[y]=y;
			}
			else{
				scanf("%d",&x);
				int px=Find(x);
				printf("%d\n",curid[px]);
			}
		}
	}

    return 0;
}

