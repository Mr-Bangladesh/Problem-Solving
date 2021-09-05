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
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

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
const int lim=1000001;
ll res[lim];
int main()
{
    linearsieve();
    res[1]=2;
    for(int i=2;i<lim;i++){
        ll x=bigmod(2,i,MOD);
        if(binary_search(Primes.begin(),Primes.end(),i)){
            x=1;
        }
        res[i]=(res[i-1]+x)%MOD;
    }

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",res[n]);
    }

    return 0;
}


