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
#define base 313
#define base1 431
#define MOD1 999987337
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

//set<ll> ans[1005],ans1[1005];
unordered_set<ll> ans[1005],ans1[1005];
ll power[1000005],power1[1000005];
int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	power[0]=1; power1[0]=1;
	for(int i=1;i<=1e6;i++){
		power[i]=(1LL*power[i-1]*base)%MOD;
		power1[i]=(1LL*power1[i-1]*base1)%MOD1;
	}
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1],b[m+1];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]++;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		b[i]++;
	}
	
	ll hash1[n+1],hash2[m+1];
	ll hash3[n+1],hash4[m+1];
	hash1[0]=hash2[0]=hash3[0]=hash4[0]=0;
	for(int i=1;i<=n;i++){
		hash1[i]=(1LL*hash1[i-1]*base + a[i])%MOD;
		hash3[i]=(1LL*hash3[i-1]*base1 + a[i])%MOD1;
		//cout<<i<<"  "<<hash3[i]<<endl;
	}
	for(int i=1;i<=m;i++){
		hash2[i]=(1LL*hash2[i-1]*base + b[i])%MOD;
		hash4[i]=(1LL*hash4[i-1]*base1 + b[i])%MOD1;
		//cout<<i<<" "<<hash2[i]<<endl;
	}
	
	for(int len=1;len<=m;len++){
		for(int i=1;i+len-1<=m;i++){
			//cout<<i<<" "<<i+len-1<<endl;
			int j=i+len-1;
			ll cur=(hash2[j]-(hash2[i-1]*power[j-i+1])%MOD)%MOD;
			ll cur1=(hash4[j]-(hash4[i-1]*power1[j-i+1])%MOD1)%MOD1;
			if(cur<0) cur+=MOD;
			if(cur1<0) cur1+=MOD1;
			ans[len].insert(cur);
			ans1[len].insert(cur1);
			//cout<<len<<" "<<cur<<" "<<cur1<<endl;
			//cout<<len<<" "<<cur1<<endl;
		}
	}
	
	int q,cs=1,x;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		int cur=a[x];
		int l=1,r=min(n-x+1,m);
		int res=0;
		while(l<=r){
			int mid=(l+r)/2;
			int y=x+mid-1;
			ll check=(hash1[y]-(hash1[x-1]*power[y-x+1])%MOD)%MOD;
			ll check1=(hash3[y]-(hash3[x-1]*power1[y-x+1])%MOD1)%MOD1;
			if(check<0) check+=MOD;
			if(check1<0) check1+=MOD1;
			//cout<<mid<<" "<<check<<" "<<check1<<endl;
			//cout<<mid<<" "<<check1<<endl;
			
			if(ans[mid].find(check)!=ans[mid].end() && ans1[mid].find(check1)!=ans1[mid].end()){
				res=mid; //cout<<"OK"<<endl;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		printf("Query %d: %d\n",cs++,res);
	}

    return 0;
    //you should actually read the stuff at the bottom
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smooth instead of nothing and stay organized
	* don't get stuck on one approach, try another
	* don't waste time in one problem, try another
	* check PI value acos(-1.0)
*/