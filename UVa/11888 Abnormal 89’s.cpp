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
ll p[maxn],h1[maxn],h2[maxn],h3[maxn],h4[maxn];
struct Hashing{
	string s; 
	int n;
	Hashing(string _s,int _n){
		s=_s;
		n=_n;
		for(int i=0;i<=n;i++){
			p[i]=h1[i]=h2[i]=h3[i]=h4[i]=0;
		}
	}
	void build(){
		p[0]=1;
		for(int i=1;i<=n;i++){
			p[i]=(p[i-1]*base) %MOD;
		}
		for(int i=1;i<=n;i++){
			h1[i]=(h1[i-1]*base + s[i-1]-96)%MOD;
			h2[i]=((s[i-1]-96)*p[i-1]+h2[i-1]) %MOD;
			//cout<<"prefix  "<<i<<"  "<<h1[i]<<" "<<h2[i]<<endl;
		}
		string t=s;
		reverse(t.begin(),t.end());
		for(int i=1;i<=n;i++){
			h3[i]=(h3[i-1]*base + (t[i-1]-96))%MOD;
			h4[i]=((t[i-1]-96)*p[i-1]+h4[i-1]) %MOD;
		}
	}
	bool prefixpal(int k){
		ll a=h1[k];
		ll b=h2[k];
		//cout<<"prefix "<<k<<" "<<a<<" "<<b<<endl;
		return (a==b);
	}
	bool suffixpal(int k){
		k=n-k+1;
		ll a=h3[k];
		ll b=h4[k];
		//cout<<"suffix "<<k<<" "<<a<<" "<<b<<endl;
		return (a==b);
	}
};

int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int len=s.length();
		Hashing h = Hashing(s,len);
		h.build();
		int check=-1;
		for(int i=1;i<len;i++){
			//cout<<i<<endl;
			bool a=h.prefixpal(i);
			bool b=h.suffixpal(i+1);
			//cout<<i<<" "<<a<<" "<<b<<endl;
			if(a==b && a==1){
				check=2;
				break;
			}
		}
		if(check==2){
			cout<<"alindrome"<<endl;
			continue;
		}
		if(h.prefixpal(len) && h.suffixpal(1)){
			cout<<"palindrome"<<endl;
		}
		else{
			cout<<"simple"<<endl;
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