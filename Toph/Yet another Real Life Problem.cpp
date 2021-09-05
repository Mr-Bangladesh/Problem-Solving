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
#define maxn 100005

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}
//char s[maxn];
string res,s;

#define MAX_NODE 5000005
int root,indx,tri[MAX_NODE][30],endpoint[MAX_NODE],substrcnt[MAX_NODE][30];
struct Trie{
	Trie(){
		root=indx=0;
	    for(int i=0;i<26;i++){
	        tri[root][i]=-1;
	    }
	}
	void Add(int n){
	    int now=root;
	    for(int i=0;i<n;i++){
	        if(tri[now][s[i]-'a']==-1){
	            tri[now][s[i]-'a']=++indx;
	            for(int j=0;j<26;j++){
	                tri[indx][j]=-1;
	            }
	        }
	        substrcnt[now][s[i]-'a']++; // ei node e sesh hoiche emon koyta string
	        now=tri[now][s[i]-'a'];
	    }
	    endpoint[now]++;
	}
	bool Find(int n){
	    int now=root;
	    for(int i=0;i<n;i++){
	        if(tri[now][s[i]-'a']==-1 || substrcnt[now][s[i]-'a']==0){
	        	return false;	
	        }
	        res+=s[i];
	        now=tri[now][s[i]-'a'];
	    }
	    while(!endpoint[now]){
	    	bool check=false;
	    	for(int i=0;i<26;i++){
	    		if(tri[now][i]!=-1){
	    			res+=(i+'a');
	    			now=tri[now][i];
	    			check=true;
	    			break;
	    		}
	    	}
	    	if(!check){
	    		return false;
	    	}
	    }
	    return endpoint[now];
	}
};

int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	int q,x;
	//scanf("%d",&q);
	cin>>q;
	
	Trie t=Trie();
	
	while(q--){
		//scanf("%d %s",&x,&s);
		cin>>x>>s;
		//int len=strlen(s);
		int len = s.length();
		if(x==1){
			t.Add(len);
		}
		else{
			if(s[0]=='.'){
				res="";
				bool cur = t.Find(0);
				if(!cur) cout<<"No word found!"<<endl;
				else cout<<res<<endl;
			}
			else{
				res="";
				bool cur=t.Find(len);
				if(cur){
					cout<<res<<endl;
				}
				else{
					cout<<"No word found!"<<endl;
					//printf("No word found!\n");
				}
			}
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