// Problem: Find the primes?
// Contest: Toph
// URL: https://toph.co/p/find-the-primes
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
// ll power(ll x,ll y,ll p){
    // ll res=1;
    // x=x%p;
    // while(y>0){
        // if(y&1) res=(res*x)%p;
        // y=y>>1;
        // x=(x*x)%p;
    // }
    // return res;
// }
// 
// bool millerTest(ll d,ll n)
// {
    // ll a=2+ rand()%(n-4);
    // ll x=power(a,d,n);
    // if(x==1 || x==n-1) return true;
    // while(d!=n-1){
        // x=(x*x)%n;
        // d*=2;
        // if(x==1) return false;
        // if(x==n-1) return true;
    // }
    // return false;
// }
// 
// 
// bool isprime(ll n)
// {
	// ll k=5;
    // if(n<=1 || n==4) return false;
    // if(n<=3) return true;
    // ll d=n-1;
    // while(d%2==0) d/=2;
    // for(ll i=0;i<k;i++)
        // if(!millerTest(d,n))
            // return false;
    // return true;
// }
// 
// ll phisum(ll n){
	// ll sum=n*n;
	// ll hor=2;
	// ll lob=1;
	// for(int i=0;i<Primes.size() && Primes[i]*Primes[i]<=n;i++){
// 		
		// if(isprime(n)) break;
// 		
		// if(n%Primes[i]) continue;
		// lob*=(Primes[i]-1);
		// hor*=Primes[i];
		// while(n%Primes[i]==0) n/=Primes[i];
	// }
	// if(n!=1){
		// lob*=(n-1);
		// hor*=n;
	// }
	// sum=(sum*lob)/hor;
	// return sum;
// }

ll A[5000005];
ll lim=5000000;
void phi()
{
    for(ll i=2;i<=lim;i++) A[i]=i*i;
    for(ll x:Primes){
        for(ll i=x;i<=lim;i+=x){
            A[i]=(A[i]*(x-1))/x;
        }
    }
    for(int i=1;i<=lim;i++) A[i]/=2;
}

int main()
{
	linearsieve();
	phi();
	
	for(int i=2;i<=100;i++) cout<<i<<" "<<A[i]<<endl;
	
	// int t;
	// scanf("%d",&t);
	// while(t--){
		// ll n;
		// scanf("%lld",&n);
// 		
		// ll l=2,r=1e12,ans=-1;
		// while(l<=r){
			// ll mid=(l+r)/2;
// 			
			// ll cursum=phisum(mid);
			// if(cursum==n){
				// ans=mid;
				// break;
			// }
			// if(cursum>)
		// }
// 		
	// }
	

    return 0;
}

