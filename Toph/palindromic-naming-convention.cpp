// Problem: Palindromic Naming Convention
// Contest: Toph
// URL: https://toph.co/p/palindromic-naming-convention
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
#define base 89
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

ll power[maxn];

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	power[0]=1;
	for(int i=1;i<maxn;i++){
		power[i]=(power[i-1]*base)%MOD;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		
		char str[maxn];
		scanf("%s",str);
		ll h=0,h1=0;
		int len=strlen(str);
		for(int i = 0;i < len; i++){
			h=(h*base+str[i]-96)%MOD;
			h1=((str[i]-96)*power[i]+h1)%MOD;
		}
		//cout<<h<<" "<<h1<<endl;
		ll cur=0,next=0;
		
		char ans[maxn];
		
		for(int i=0;i<len;i++){
			cur=(cur*base+str[i]-96)%MOD;
			next=((str[i]-96)*power[i]+next)%MOD;
			
			ans[i]=str[i];
			//cout<<cur<<" "<<next<<endl;
			
			ll tmp1=(h*power[i+1]+next)%MOD;
			ll tmp2=(cur*power[len]+h1)%MOD;
			//cout<<tmp1<<" "<<tmp2<<endl;
			if(tmp1==tmp2){
				break;
			}
		}
		char tmp[maxn];
		len=strlen(ans);
		for(int i=0,j=len-1;i<len;i++,j--){
			tmp[i]=ans[j];
		}
		printf("%s %s\n",str,tmp);
		
		for(int i=0;i<maxn;i++){
			str[i]=ans[i]=tmp[i]='\0';
		}
		
		//printf("%s %s %s\n",str,ans,tmp);
		
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