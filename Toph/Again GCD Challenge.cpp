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

#define MAX 200001
vector<int> Primes;
int least[MAX];
void linearsieve(){
    for(int i=2;i<MAX;i++){
        if(!least[i]){
            least[i]=i;
            Primes.pb(i);
        }
        for(int x:Primes){
            if(x>least[i] | i*x>=MAX) break;
            least[i*x]=x;
        }
    }
}

int a[maxn];
vector<int> g[maxn];
void pre(){
	for(int x:Primes){
		for(int i=x;i<maxn;i+=x){
			g[i].pb(x);
		}
	}
}

int f(int l,int r){
	map<int,int> last;
	int i=l,j=l,res=0;
	while(i<=r && j<=r){
		
		for(int x:g[a[j]]){
			if(last.find(x)!=last.end() && last[x]>=i){
				i=last[x]+1;
			}
			last[x]=j;
		}
		res=max(res,j-i+1);
		j++;
	}
	if(res==1) res=0;
	return res;
}

int main()
{
	//what the hell are youing? Think again before coding.
	FastIO();
	
	linearsieve();
	
	pre();
	
	int n,x;
	
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%x) a[i]=-1;
		else a[i]/=x;
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++){
		if(a[i]==-1) continue;
		int j=i;
		while(j+1<=n && a[j+1]!=-1){
			j++;
		}
		//cout<<i<<" "<<j<<endl;
		//if(f(i,j)){
			ans=max(ans,f(i,j));
		//}
		i=j;
	}
	
	cout<<ans<<endl;
	

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