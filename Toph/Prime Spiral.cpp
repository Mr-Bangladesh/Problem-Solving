/**In the name of Allah, the Most Merciful, the Most Merciful.**/
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
vector<ll> Primes;
ll const MAX = 100000000;
bitset<MAX> prime;
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for(ll i = 2; i * i < MAX; ++i)
        if(prime[i])
            for(ll j = i * i; j < MAX; j += i)
                prime[j] = 0;
    for(int i=2;i<=MAX;i++){
        if(prime[i]) Primes.pb(i);
    }
}
int main()
{
    sieve();

    int n,q,x,y;
    cin>>n>>q;

    int a[n+1][n+1];
    memset(a,0,sizeof(a));
    int l,r;
    if(n%2){
        l=r=n/2+1;
    }
    else{
        l=n/2+1; r=n/2;
    }
    int curx=l,cury=r,idx=2;
    a[l][r]=1;
    for(int i=1;i<n;i++){
        if(i%2){
            int tmp=cury+i;
            for(int k=cury+1;k<=tmp;k++){
                a[curx][k]=idx++;
            }
            cury=tmp;
            tmp=curx-i;
            for(int k=curx-1;k>=tmp;k--){
                a[k][cury]=idx++;
            }
            curx=tmp;
        }
        else{
            int tmp=cury-i;
            for(int k=cury-1;k>=tmp;k--){
                a[curx][k]=idx++;
            }
            cury=tmp;
            tmp=curx+i;
            for(int k=curx+1;k<=tmp;k++){
                a[k][cury]=idx++;
            }
            curx=tmp;
        }
    }

    if(n%2){
        for(int i=2;i<=n;i++){
            a[n][i]=idx++;
        }
    }
    else{
        for(int i=n-1;i>=1;i--){
            a[1][i]=idx++;
        }
    }

//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++) cout<<a[i][j]<<" " ; cout<<endl;
//    }

    while(q--){
        cin>>x>>y;
        int idx=a[x][y];
        cout<<Primes[idx-1]<<endl;
    }

    return 0;
}


