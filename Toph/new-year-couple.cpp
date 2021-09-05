// Problem: New Year Couple
// Contest: Toph
// URL: https://toph.co/p/new-year-couple
// Memory Limit: 1024 MB
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
#define maxn 200005

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

struct Person{
	int typ, idx, time, l, r;
	Person(int a,  int b, int c, int d, int e){
		typ = a, idx = b, time = c, l = d, r = e;
	}
};
bool cmp(Person a, Person b){
	if(a.time == b.time){
		return a.typ < b.typ;
	}
	return a.time < b.time;
}
char s[30005][55];
vector<Person> person;
int res[55][55];

struct Trie{
	struct node{
		int cnt,endpoint;
		int child[26];
		node(){
			cnt=0; endpoint=0;
			for(int i=0;i<26;i++){
				child[i]=-1;
			}
		}
	} root;
	vector<node> tri;
	int indx;
	Trie(){
		indx=0;
		tri.pb(root);
	}
	void Add(int idx,int len,int b){
		int now=0;
		//cout<<idx<<" "<<b<<" "<<s[idx]<<endl;
		for(int i=b;i<len;i++){
			int id=s[idx][i]-'a';
			if(tri[now].child[id]==-1){
				tri[now].child[id]=++indx;
				node next=node();
				tri.pb(next);
			}
			now=tri[now].child[id];
			tri[now].cnt++;
			//cout<<idx<<" "<<b+1<<" "<<i+1<<" "<<tri[now].cnt<<endl;
			res[b][i]+=(tri[now].cnt-1);
		}
		tri[now].endpoint++;
	}
	void Delete(int idx,int len,int b){
		int now=0;
		for(int i=b;i<len;i++){
			int id=s[idx][i]-'a';
			now=tri[now].child[id];
			tri[now].cnt--;
			res[b][i]-=(tri[now].cnt);
		}
		tri[now].endpoint--;
	}
}tr[55];

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	int n,b,e;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%s %d %d",s[i], &b, &e);
		person.pb(Person(1, i, b, 0, 0));
		person.pb(Person(3, i, e, 0, 0));
	}
	int q,x,y,k;
	scanf("%d",&q);
	
	for(int i = 0;i < q;i++){
		scanf("%d %d %d",&x, &y, &k); x--; y--;
		person.pb(Person(2, i, k, x, y));
	}
	
	sort(person.begin(), person.end(),cmp);
	
	for(int i=0;i<=50;i++){
		tr[i] = Trie();
	}
	int ans[q];
	for(auto it : person){
		int typ = it.typ, l = it.l, r = it.r, time = it.time, idx = it.idx;
		if(typ  == 1){
			int len=strlen(s[idx]);
			for(int i=0;i<len;i++){
				tr[i].Add(idx,len,i);
			}
		}
		else if(typ == 2){
			ans[idx] = res[l][r];
		}
		else{
			int len=strlen(s[idx]);
			for(int i=0;i<len;i++){
				tr[i].Delete(idx,len,i);
			}
		}
	}
	
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);

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