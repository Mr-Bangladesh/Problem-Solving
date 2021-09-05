// Problem: Photo Matching
// Contest: Toph
// URL: https://toph.co/p/photo-matching
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
#define base 313
#define base1 431
#define MOD1 999987337
#define maxm 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

char str1[3005][3005],str2[3005][3005];
int mark[1<<17];
int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		
		for(int i=0;i<n;i++){
			scanf("%s",str1[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%s",str2[i]);
		}
		
		if(k>n){
			printf("Case %d: 0\n",cs++);
			continue;
		}
		
		//unordered_map<int,int,custom_hash> ans;
		for(int i=0;i<n-k+1;i++){
			for(int j=0;j<n-k+1;j++){
				int cur=0,bi=0;
				for(int x=i;x<i+k;x++){
					for(int y=j;y<j+k;y++){
						if(str1[x][y]=='1'){
							cur=(cur|(1<<bi));
						}
						bi++;
					}
				}
				//ans[cur]++;
				mark[cur]++;
			}
		}
		ll cnt=0;
		for(int i=0;i<n-k+1;i++){
			for(int j=0;j<n-k+1;j++){
				int cur=0,bi=0;
				for(int x=i;x<i+k;x++){
					for(int y=j;y<j+k;y++){
						if(str2[x][y]=='1'){
							cur=(cur|(1<<bi));
						}
						bi++;
					}
				}
				cnt+=(ll)mark[cur];
				// if(ans.find(cur)!=ans.end()){
					// cnt+=ans[cur];
				// }
			}
		}
		printf("Case %d: %lld\n",cs++,cnt);
		
		memset(mark,0,sizeof(mark));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				str1[i][j]=str2[i][j]='\0';
			}
		}
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