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

int prefix_function(string pat,int m){
	vector<int> lps(m);
	lps[0]=0;
	for(int i=1;i<m;i++){
		int j=lps[i-1];
        while(j>0 && pat[i]!=pat[j])
            j = lps[j-1];
        if (pat[i]==pat[j])  ++j;
        lps[i]=j;
	}
	return lps.back();
}
int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	string s;
	while(cin>>s){
		int len=s.length();
		string t=s;
		reverse(t.begin(),t.end());
		t+="*";
		t+=s;
		int len1=t.length();
		int cur=prefix_function(t,len1);
		string tmp="";
		for(int i=0;i<len-cur;i++){
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