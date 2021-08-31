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

#define MAX 1000001
ll phi[MAX], result[MAX];
void computeTotient(){
    phi[1] = 1;
    for (int i=2; i<MAX; i++){
        if (!phi[i]){
            phi[i] = i-1;
            for (int j = (i<<1); j<MAX; j+=i){
                if (!phi[j]){
                    phi[j] = j;
                }
                phi[j] = (phi[j]/i)*(i-1);
            }
        }
    }
}

ll ans[MAX];
void precalc(){
    for(ll i=1;i<MAX;i++){
        for(ll j=i;j<MAX;j+=i){
            ll tmp=i*phi[i];
            ans[j]+=tmp;
        }
    }
}

int main()
{
    computeTotient();
    precalc();

    //for(int i=1;i<=10;i++) cout<<i<<" "<<ans[i]<<endl;

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        ll res=(n*(ans[n]+1))/2;
        printf("%lld\n",res);
    }


    return 0;
}


