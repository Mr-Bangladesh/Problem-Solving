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
string res;

struct Trie{
	struct node {
	    bool endmark;
	    node* next[26 + 1];
	    node(){
	        endmark = false;
	        for (int i = 0; i < 26; i++){
	            next[i] = NULL;
	        }
	    }
	} * root;
	
	Trie(){
		root=new node();
	}
	void Add(string s,int len){
	    node* cur=root;
	    for(int i=0;i<len;i++){
	        int id=s[i]-'a';
	        if(cur->next[id]==NULL){
	            cur->next[id]=new node();
	        }
	        cur=cur->next[id];
	    }
	    cur->endmark=true;
	}
	void Delete(node* cur){ //we can clear whole trie Delete(root)
	    for (int i = 0; i < 26; i++)
	        if (cur->next[i])
	            Delete(cur->next[i]);
	    delete (cur);
	}
	bool Find(string str, int len){
	    node* curr = root;
	    for (int i = 0; i < len; i++) {
	        int id = str[i] - 'a';
	        if (curr->next[id] == NULL)
	            return false;
	        curr = curr->next[id];
	        res+=str[i];
	        //cout<<id<<endl;
	    }
	    
	    while(!curr->endmark){
	    	//cout<<"OK"<<endl;
	    	bool check=false;
	    	for(int i=0;i<26;i++){
	    		if(curr->next[i]!=NULL){
	    			curr=curr->next[i];
	    			res+=(i+'a');
	    			check=true;
	    			//cout<<i<<endl;
	    			break;
	    		}
	    	}
	    	if(!check){
	    		return false;
	    	}
	    }
	    
	    return curr->endmark;
	}
};

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	
	int q,x;
	//scanf("%d",&q);
	cin>>q;
	
	Trie t=Trie();
	string s;
	while(q--){
		//scanf("%d %s",&x,&s);
		cin>>x>>s;
		//int len=strlen(s);
		int len = s.length();
		if(x==1){
			t.Add(s,len);
		}
		else{
			if(s[0]=='.'){
				res="";
				bool cur=t.Find("",0);
				if(!cur) cout<<"No word found!"<<endl;
				else cout<<res<<endl;
			}
			else{
				res="";
				bool cur=t.Find(s,len);
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