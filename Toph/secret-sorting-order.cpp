// Problem: Secret Sorting Order
// Contest: Toph
// URL: https://toph.co/p/secret-sorting-order
// Memory Limit: 1024 MB
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
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

vector<int> g[30];
int indeg[30];
set< pair<char,char> > mark;
set<int> node;

void add(string a,string b){
	
	int n=a.length(); int m=b.length();
	
	for(int i=0;i<min(n,m);i++){
		if(a[i]!=b[i]){
			
			if(mark.find(mp(a[i],b[i]))!=mark.end()) break;
			
			mark.insert(mp(a[i],b[i]));
			//mark.insert(mp(b[i],a[i]));
			
			indeg[b[i]-96]++;
			
			g[a[i]-96].pb(b[i]-96);
			
			//node.insert(a[i]-96);
			//node.insert(b[i]-96);
			//cout<<a<<" "<<b<<" "<<i<<" "<<a[i]<<" "<<b[i]<<endl;
			//cout<<a[i]<<" "<<b[i]<<endl;
			break;
		}
	}
}

vector<int> bfs(){
	queue<int> q;
	for(int i:node){
		//cout<<i<<" "<<indeg[i]<<endl;
		if(indeg[i]==0) q.push(i);
	}
	
	vector<int> cur;
	
	while(!q.empty()){
		int u=q.front(); q.pop();
		cur.pb(u);
		for(int v:g[u]){
			if(indeg[v]) indeg[v]--;
			//cout<<u<<" "<<v<<" "<<indeg[v]<<endl;
			if(indeg[v]==0) q.push(v);
		}
	}
	return cur;
}

void init(){
	for(int i=1;i<30;i++){
		g[i].clear();
		indeg[i]=0;
	}
	node.clear();
	mark.clear();
}

int main()
{
	int t,cs=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		init();
		string s[n];
		
		for(int i=0;i<n;i++){
			cin>>s[i];
			int len=s[i].length();
			for(int j=0;j<len;j++){
				node.insert(s[i][j]-96);
			}
		}
		
		for(int i=0;i<n-1;i++){
			//cout<<i<<" "<<i+1<<endl;
			add(s[i],s[i+1]);
		}
		vector<int> ans=bfs();
		
		string res="";
		for(int i:ans){
			res+=(i+96);
		}
		int len=res.length();
		for(int i=0;i<len;i++){
			if(i) cout<<" ";
			cout<<res[i];
		}
		cout<<endl;
		
	}

    return 0;
}

