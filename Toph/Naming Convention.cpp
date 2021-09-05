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

int n;
string s[1005];
ll Hash[1005][105],power[1005];
void pre(){
	power[0]=1;
	for(int i=1;i<=n;i++){
		power[i]=(power[i-1]*base)%MOD;
		Hash[i][0]=0;
		int len=s[i].length();
		for(int j=1;j<=len;j++){
			Hash[i][j]=(Hash[i][j-1]*base+(s[i][j-1]-96))%MOD;
		}
	}
}

ll gethash(int i,int a,int b){
	return (Hash[i][b]-(Hash[i][a-1]*power[b-a+1])%MOD+MOD)%MOD;
}

int dp[105][105];
int source,len1;
int f(int i,int cnt){
	if(i>len1) return 0;
	if(i==len1){
		if(cnt>1) return 1;
		return 0;
	}
	if(dp[i][cnt]!=-1) return dp[i][cnt];
	
	int res=0;
	
	for(int k=1;k<=n;k++){
		if(k==source) continue;
		int len=s[k].length();
		if(i+len>len1) continue;
		ll txt=gethash(source,i+1,i+len);
		ll pat=gethash(k,1,len);
		
		//cout<<source<<" "<<i<<" "<<k<<" "<<len<<" "<<txt<<" "<<pat<<endl;
		
		if(txt==pat){
			res|=f(i+len,cnt+1);
		}
	}
	return dp[i][cnt]=res;
}

int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	pre();
	bool check=false;
	for(int i=1;i<=n;i++){
		memset(dp,-1,sizeof(dp));
		source=i;
		len1=s[i].length();
		if(f(0,0)){
			check=true;
			cout<<s[i]<<" ";
		}
	}
	if(!check){
		cout<<"No solution"<<endl;
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