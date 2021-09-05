// Problem: Is It A Square?
// Contest: Toph
// URL: https://toph.co/p/is-it-a-square
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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
#define maxn 100005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}

#define MAX 100001
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

ll hashval[maxn];

void pre(){
	hashval[0]=0;
	hashval[1]=0;
	for(int n=2;n<maxn;n++){
		int m=n;
		ll cur=0;
		for(int i=0;i<Primes.size() && Primes[i]*Primes[i]<=m;i++){
			if(m%Primes[i]) continue;
			while(m%Primes[i]==0){
				cur=(cur^(1LL<<Primes[i])%MOD)%MOD;
				m/=Primes[i];
			}
		}
		if(m!=1){
			cur=(cur^(1LL<<n)%MOD)%MOD;
		}
		hashval[n]=cur;
	}
}

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	linearsieve();
	pre();
	//cout<<hashval[36]<<endl;
	
	int n,q;
	scanf("%d %dd",&n,&q);
	
	int a[n+1],sign[n+1]={0},zero[n+1]={0};
	
	ll res[n+1];
	res[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		
		zero[i]=zero[i-1]+(a[i]==0);
		
		if(a[i]<0){
			sign[i]=sign[i-1]+1;
			a[i]=abs(a[i]);
		}
		else{
			sign[i]=sign[i-1];
		}
		res[i]=(res[i-1]^hashval[a[i]])%MOD;
	}
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		
		if(zero[y]-zero[x-1]){
			printf("Yes\n");
			continue;
		}
		
		ll cur=(res[y]^res[x-1])%MOD;
		int cnt=sign[y]-sign[x-1];
		
		//cout<<cur<<" "<<cnt<<endl;
		
		if(cur) printf("No\n");
		else{
			if(cnt%2) printf("No\n");
			else printf("Yes\n");
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