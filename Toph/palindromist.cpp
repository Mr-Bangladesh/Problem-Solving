// Problem: Palindromist
// Contest: Toph
// URL: https://toph.co/p/palindromist
// Memory Limit: 512 MB
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
#define maxn 10000005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

ll base=89,p[maxn];

int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	p[0]=1;
	for(int i=1;i<maxn;i++){
		p[i]=(p[i-1]*base)%MOD;
	}
	
	int t,cs=1;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int len=s.length();
		ll h=0,r_h=0;
		for(int i=0;i<len;i++){
			h=(h*base+(s[i]-96))%MOD;
			r_h=((s[i]-96)*p[i]+r_h)%MOD;
		}
		//cout<<h<<" "<<r_h<<endl;
		int q;
		cin>>q;
		cout<<"Case "<<cs++<<":"<<endl;
		string a,b; int k;
		while(q--){
			cin>>a>>b>>k;
			if(a=="L"){
				ll cur=0;
				for(int i=0;i<k;i++){
					cur=(cur*base+(b[0]-96))%MOD;
				}
				h=(cur*p[len]+h)%MOD;
				r_h=(r_h*p[k]+cur)%MOD;
			}
			else{
				ll cur=0;
				for(int i=0;i<k;i++){
					cur=(cur*base+(b[0]-96))%MOD;
				}
				h=(h*p[k]+cur)%MOD;
				r_h=(cur*p[len]+r_h)%MOD;
			}
			len+=k;
			//cout<<h<<" "<<r_h<<endl;
			if(h==r_h){
				cout<<"Yes"<<endl;
			}
			else cout<<"No"<<endl;
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