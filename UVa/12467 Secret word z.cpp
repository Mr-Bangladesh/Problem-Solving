// Problem: 12467 - Secret Word
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3911
// Memory Limit: 32 MB
// Time Limit: 2000 ms
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
#define maxn 1000005

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

char str[maxn],pat[2*maxn];
int z[2*maxn];

void Z(){
	int len=strlen(pat);
	for(int i=1,l=0,r=0;i<len;i++){
		if(i<=r){
			z[i]=min(r-i+1,z[i-l]);
		}
		while(i+z[i]<len && pat[i+z[i]]==pat[z[i]]){
			z[i]++;
		}
		if(i+z[i]-1>r){
			l=i;
			r=i+z[i]-1;
		}
	}
}

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;i++){
			pat[i]=str[i];
		}
		pat[len]='*';
		for(int i=0;i<len;i++){
			pat[len+i+1]=str[len-i-1];
		}
		
		Z();
		int mx=0;
		for(int i=len;i<=len*2;i++){
			//cout<<z[i]<<" ";
			mx=max(mx,z[i]);
		}
		
		//cout<<endl;
		
		//cout<<mx<<endl;
		
		for(int i=mx-1;i>=0;i--){
			printf("%c",str[i]);
		}
		printf("\n");
		
		for(int i=0;i<=len*2;i++){
			pat[i]='\0';
			z[i]=0;
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