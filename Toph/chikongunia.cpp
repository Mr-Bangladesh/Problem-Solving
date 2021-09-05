// Problem: Chikongunia
// Contest: Toph
// URL: https://toph.co/p/chikongunia
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
#define maxn 100005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

ull h[maxn],p[maxn],base=89;
void hashing(string s){
	int n=s.length();
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=(p[i-1]*base);
		h[i]=(h[i-1]*base+(s[i-1]-96));
	}
}
ull gethash(int a,int b){
	if(a>b) return 0;
	return (h[b]-(h[a-1]*p[b-a+1]));
}

int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	int n,m;
	cin>>n>>m;
	string s[n];
	map<ull,ull> cnt;
	for(int i=0;i<n;i++){
		cin>>s[i];
		hashing(s[i]);
		ull x=gethash(1,m);
		cnt[x]++;
	}
	ull ans=0;
	for(int i=0;i<n;i++){
		hashing(s[i]);
		ull cur=gethash(1,m);
		for(int j=0;j<m;j++){
			for(char c='a';c<='z';c++){
				if(s[i][j]==c) continue;
				ull l=gethash(1,j); ull r=gethash(j+2,m);
				ull cur1=(l*base+(c-96));
				//cout<<l<<" "<<r<<" "<<c<<" "<<j<<" "<<cur1<<endl;
				//cout<<cur1<<" "<<p[m-j]<<endl;
				cur1=(cur1*p[m-j-1]+r);
				
				//cout<<j<<" "<<s[i][j]<<" "<<c<<" "<<cur1<<endl;
				//cout<<l<<" "<<r<<endl;
				if(cnt.find(cur1)!=cnt.end()){
					ans+=cnt[cur1];
					//cout<<i<<" "<<j<<" "<<s[i][j]<<" "<<c<<" "<<cur1<<endl;
					//cout<<cur<<"        "<<cur1<<endl;
				}
			}
		}
	}
	cout<<ans/2<<endl;
	

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