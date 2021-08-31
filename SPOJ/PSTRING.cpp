// Problem: Remove The String
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/PSTRING/
// Memory Limit: 1536 MB
// Time Limit: 1265 ms
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
#define base 313
#define base1 431
#define MOD1 999987337
#define maxm 200005
#define maxn 200005

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

string text,pat;
int n,m,dp[10005][1005];
int lps[1005];
void prefix_function(){
	lps[0]=0;
	for(int i=1;i<m;i++){
		int j=lps[i-1];
		while(j>0 && pat[i]!=pat[j]){
			j=lps[j-1];
		}
		if(pat[i]==pat[j]){
			j++;
		}
		lps[i]=j;
	}
}
int f(int idx,int len){// idx = cur idx of text, len = mathching length of text with pat
	if(idx >= n) return 0;
	int &ret = dp[idx][len];
	if(ret != -1) return ret;
	int cur = len;
	while(cur>0 && text[idx]!=pat[cur]){
		cur = lps[cur-1];
	}
	if(text[idx] == pat[cur]){
		if(cur+1==m){ // get a matching -> must remove cur char
			ret = 1 + f(idx+1,len);
		}
		else{
			int p = 1 + f(idx+1,len); // remove cur char from text
			int q = f(idx+1,cur+1); // won't remove from text
			ret = min(p,q);
		}
	}
	else{
		ret = f(idx+1,cur); // won't remove from text
	}
	//cout<<idx<<" "<<len<<" "<<ret<<endl;
	return ret;
}


int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	while(cin>>text>>pat){
		n = text.length(); m = pat.length();
		
		memset(dp,-1,sizeof(dp));
		memset(lps,0,sizeof(lps));
		
		prefix_function();
		int ans=f(0,0);
		
		cout<<ans<<endl;
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