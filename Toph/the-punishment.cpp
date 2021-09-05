// Problem: The Punishment of Hasinur
// Contest: Toph
// URL: https://toph.co/p/the-punishment
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#include <bits/stdc++.h>
using namespace std;
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
#define maxn 500005

ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

#define MAX_NODE 5000005
int root,indx,idx[MAX_NODE],trie[MAX_NODE][30],endpoint[MAX_NODE],substrcnt[MAX_NODE][30];
int cnt[MAX_NODE],val[MAX_NODE];
struct Trie{
	Trie(){
		root=indx=0;
	    for(int i=0;i<26;i++){
	        trie[root][i]=-1;
	    }
	}
	void Add(string s,int n,int k){
	    int now=root;
	    for(int i=0;i<n;i++){
	        if(trie[now][s[i]-'a']==-1){
	            trie[now][s[i]-'a']=++indx;
	            //cout<<"add "<<s[i]<<" "<<trie[now][s[i]-'a']<<endl;
	            for(int j=0;j<26;j++){
	                trie[indx][j]=-1;
	            }
	        }
	        substrcnt[now][s[i]-'a']++; // ei node e sesh hoiche emon koyta string
	        now=trie[now][s[i]-'a'];
	    }
	    endpoint[now]++;
	    idx[now]=k;
	    //cout<<k<<" "<<now<<" "<<endpoint[now]<<" "<<idx[now]<<endl;
	}
	bool Find(string s,int n){
	    int now=root;
	    for(int i=0;i<n;i++){
	        if(trie[now][s[i]-'a']==-1 || substrcnt[now][s[i]-'a']==0){
	        	return false;	
	        }
	        now=trie[now][s[i]-'a'];
	    }
	    return endpoint[now];
	}
	void Delete(string s,int n){
	    int now=root;
	    for(int i=0;i<n;i++){
	        substrcnt[now][s[i]-'a']--;
	        now=trie[now][s[i]-'a'];
	    }
	    endpoint[now]--;
	}
	void dfs(int now=root){
		cnt[now]=endpoint[now]; val[now]=idx[now];
		//cout<<now<<" "<<cnt[now]<<" "<<val[now]<<endl;
		for(int i=0;i<26;i++){
			int nxt=trie[now][i];
			if(nxt!=-1){
				dfs(nxt);
				if(cnt[nxt]>cnt[now]){
					cnt[now]=cnt[nxt];
					val[now]=val[nxt];
				}
			}
		}
		//cout<<now<<" "<<cnt[now]<<" "<<val[now]<<endl;
	}
	pair<int,int> Query(string s,int n){
		int now=root;
	    for(int i=0;i<n;i++){
	        if(trie[now][s[i]-'a']==-1 || substrcnt[now][s[i]-'a']==0){
	        	return {-1,-1};	
	        }
	        now=trie[now][s[i]-'a'];
	    }
	    return {val[now],cnt[now]};
	}
};

string s[maxn];
int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	int n;
	cin>>n;
	
	Trie t=Trie();
	
	for(int i=0;i<n;i++){
		cin>>s[i];
		int len=s[i].length();
		t.Add(s[i],len,i);
	}
	t.dfs();
	
	int q,cs=1; string a;
	cin>>q;
	while(q--){
		cout<<"Case "<<cs++<<": ";
		cin>>a;
		int len=a.length();
		pair<int,int> ans=t.Query(a,len);
		if(ans.first==-1){
			cout<<-1<<endl;
		}
		else{
			cout<<s[ans.first]<<" "<<ans.second<<endl;
		}
		//cout<<ans.first<<" "<<ans.second<<endl;
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