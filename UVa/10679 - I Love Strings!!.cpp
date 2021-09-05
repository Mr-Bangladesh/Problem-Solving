// Problem: 10679 - I Love Strings!!
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1620
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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

char s[100005],pat[1005][1005];
int fail[1000005],res[1000005],ans[1000005];

struct node{
	int cnt,endpoint;
	vector<int> id;
	int child[52];
	node(){
		cnt=endpoint=0;
		id.clear();
		for(int i=0;i<52;i++){
			child[i]=-1;
		}
	}
} root;

vector<node> tri;
int idx;

void init(){
	for(int i=0;i<=100000;i++){
		s[i]='\0';
	}
	for(int i=0;i<=1e6;i++){
		fail[i]=res[i]=ans[i]=0;
	}
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			pat[i][j]='\0';
		}
	}
	tri.clear();
	
	// for trie
	idx=0;
	tri.pb(root);
}

void Add(int cur){
	int len=strlen(pat[cur]);
	int now=0;
	for(int i=0;i<len;i++){
		int id;
		if(pat[cur][i]>='a' && pat[cur][i]<='z') id=pat[cur][i]-'a';
		else id=pat[cur][i]-'A'+26;
		
		if(tri[now].child[id]==-1){
			tri[now].child[id]=++idx;
			//cout<<pat[cur]<<" "<<pat[cur][i]<<" "<<idx<<endl;
			node next=node();
			tri.pb(next);
		}
		now=tri[now].child[id];
		tri[now].cnt++;
	}
	tri[now].endpoint++;
	tri[now].id.pb(cur);
}

void build_fail(){
	queue<int> q;
	int now=0;
	for(int i=0;i<52;i++){
		if(tri[now].child[i]!=-1){
			q.push(tri[now].child[i]);
		}
	}
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<52;i++){
			int v=tri[u].child[i];
			if(v==-1) continue;
			q.push(v);
			int x=fail[u];
			while(x>0 && tri[x].child[i]==-1){
				x=fail[x];
			}
			if(tri[x].child[i]==-1) fail[v]=0;
			else fail[v]=tri[x].child[i];
			//cout<<u<<" "<<v<<" "<<fail[v]<<endl;
		}
	}
}

void match(){
	int len=strlen(s);
	int now=0;
	for(int i=0;i<len;i++){
		int id;
		if(s[i]>='a' && s[i]<='z') id=s[i]-'a';
		else id=s[i]-'A'+26;
		//cout<<i<<" "<<s[i]<<" "<<id<<" "<<now<<endl;
		while(now>0 && tri[now].child[id]==-1){
			now=fail[now];
		}
		now=tri[now].child[id];
		if(now==-1) now=0;
		
		//cout<<i<<" "<<s[i]<<" "<<now<<endl;
		
		int temp=now;
		while(temp>0){
			res[temp]++;
			//cout<<temp<<endl;
			temp=fail[temp];
		}
	}
}

void print(int q){
	for(int i=0;i<tri.size();i++){
		if(tri[i].endpoint){
			for(int x:tri[i].id){
				if(res[i]) ans[x]=1;
				//cout<<i<<" "<<x<<" "<<res[x]<<endl;
			}
		}
	}
	for(int i=1;i<=q;i++){
		if(ans[i]) printf("y\n");
		else printf("n\n");
	}
}

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%s",s);
		int q;
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%s",pat[i]);
		}
		for(int i=1;i<=q;i++){
			Add(i);
		}
		build_fail();
		match();
		print(q);
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