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

char str[maxn],text[2*maxn],pat[maxn];

vector<int> prefix_function(){
	int m=strlen(pat);
	vector<int> lps(m);
	lps[0]=0;
	for(int i=1;i<m;i++){
		int j=lps[i-1];
		while(j>0 && pat[i]!=pat[j]){
			j=lps[j-1];
		}
		if(pat[i]==pat[j]) j++;
		lps[i]=j;
	}
	return lps;
}

bool kmp(){
	int n=strlen(text);
	int m=strlen(pat);
	vector<int> lps=prefix_function();
	int j=0;
	for(int i=0;i<n;i++){
		while(j>0 && text[i]!=pat[j]){
			j=lps[j-1];
		}
		if(text[i]==pat[j]) j++;
		if(j==m){
			if(i==n-1 || i-m+1==0) j=lps[j-1];
			else return true;
		}
	}
	return false;
}

// text = str+str --> suffix and prefix pashapashi asche and reverse order e.
// pat = rev(str)

int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int len=strlen(str);
		for(int i=0,j=len-1;i<len;i++,j--){
			text[i]=str[i];
			pat[i]=str[j];
		}
		for(int i=0;i<len;i++){
			text[len+i]=str[i];
		}
		
		if(kmp()){
			printf("alindrome\n");
		}
		else{
			bool check=true;
			for(int i=0;i<len;i++){
				if(str[i]!=pat[i]){
					check=false;
					break;
				}
			}
			if(check) printf("palindrome\n");
			else printf("simple\n");
		}
		
		for(int i=0;i<2*len;i++){
			text[i]='\0';
		}
		for(int i=0;i<len;i++){
			pat[i]=str[i]='\0';
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