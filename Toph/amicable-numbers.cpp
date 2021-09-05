// Problem: Amicable Numbers
// Contest: Toph
// URL: https://toph.co/p/amicable-numbers
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
#define maxn 10000005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

int sod[maxn];
int lim=1e7;
void pre(){
	for(int i=1;i<=lim;i++) sod[i]=1;
	for(int i=2;i<=lim;i++){
		for(int j=i;j<=lim;j+=i){
			sod[j]+=i;
		}
	}
	for(int i=1;i<=lim;i++) sod[i]-=i;
}

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}
bool mark[maxn];
vector< pair<int,int> > v;
int main()
{
	pre();
	
	//cout<<sod[lim]<<endl;
	int cnt=0;
	for(int i=2;i<=lim;i++){
		int cur=sod[i];
		if(cur>lim) continue;
		//cnt++;
		if(i!=cur && sod[cur]==i && !mark[i] && !mark[cur]){
			mark[i]=1;
			mark[cur]=1;
			cnt++;
			//cout<<i<<" "<<sod[i]<<endl;
			v.pb(mp(min(i,sod[i]),max(i,sod[i])));
		}
	}
	//cout<<cnt<<endl;
	sort(v.begin(),v.end(),cmp);
	
	//cout<<v.size()<<endl;
	
	//for(auto it:v) cout<<it.first<<" "<<it.second<<endl;
	
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("Case %d:\n",cs++);
		for(auto it:v){
			if(it.first>=a && it.second<=b) printf("%d %d\n",it.first,it.second);
		}
	}

    return 0;
}

