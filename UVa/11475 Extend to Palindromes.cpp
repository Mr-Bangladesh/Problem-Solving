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


int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	string s;
	while(cin>>s){
		int len=s.length();
		ll power[len+1];
		power[0]=1;
		for(int i=1;i<=len;i++){
			power[i]=(power[i-1]*base)%MOD;
		}
		
		ll hash1=0,hash2=0,hash3=0,hash4=0,hash5=0,hash6=0;
		
		for(int i=0;i<len;i++){
			hash1=(hash1*base + s[i])%MOD;
			hash2=(hash2+(s[i]*power[i])%MOD)%MOD;
		}
		//cout<<hash1<<" "<<hash2<<endl;
		if(hash1==hash2){
			cout<<s<<endl;
			continue;
		}
		int idx=-1;
		for(int i=0;i<len;i++){
			hash3=(hash3+(s[i]*power[i])%MOD)%MOD;
			hash4=(hash4*base + s[i])%MOD;
			//cout<<hash3<<" "<<hash4<<endl;
			ll hash5=(hash1*power[i+1] + hash3)%MOD;
			ll hash6=(hash4*power[len] + hash2)%MOD;
			//cout<<hash5<<" "<<hash6<<endl;
			if(hash5==hash6){
				idx=i;
				break;
			}
		}
		string tmp="";
		for(int i=0;i<=idx;i++){
			tmp+=s[i];
		}
		reverse(tmp.begin(),tmp.end());
		s+=tmp;
		cout<<s<<endl;
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