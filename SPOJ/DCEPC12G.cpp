// Problem: G Force
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/DCEPC12G/
// Memory Limit: 1536 MB
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
#define maxn 10000001
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}

#define MAX 10000001
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

ll phi[maxn];
void totient(){
	phi[1]=1;
	for(int i=2;i<maxn;i++) phi[i]=i-1;
	for(int i=2;i<maxn;i++){
		for(int j=i*2;j<maxn;j+=i){
			phi[j]-=phi[i];
		}
	}
}
ll bigmod(ll B,ll P,ll M){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=bigmod(B,P/2,M);
        return ((R%M)*(R%M))%M;
    }
    else{
        ll R=bigmod(B,P-1,M);
        return ((R%M)*(B%M))%M;
    }
}
ll fact[20];
ll f[maxn],g[maxn];
int main()
{
	totient();
	linearsieve();
	fact[0]=1;
	for(ll i=1;i<=15;i++) fact[i]=fact[i-1]*i;
	
	f[1]=0;
	int j=0;
	int mx=0;
	for(int i=2;i<maxn;i++){
		while(j<Primes.size() && Primes[j]<=i){
			j++;
		}
		f[i]=max(0,j-phi[i]);
		mx=max(mx,f[i]);
		//cout<<i<<" "<<f[i]<<endl;
	}
	//cout<<mx<<endl;
	
	for(int i=1;i<maxn;i++){
		g[i]=bigmod(phi[i],fact[f[i]],MOD);
	}
	
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",g[n]);
	}

    return 0;
}

