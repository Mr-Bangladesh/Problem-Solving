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

int main()
{
    int n;
    cin>>n;
    ll a[n+1],cnt[3005]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    ll res=0;
    for(int i=2;i<=3000;i++){
        if(!cnt[i]) continue;
        ll x=0;
        ll y=(cnt[i]*(cnt[i]-1))/2;
        for(int j=i+1;j<=3000;j++){
            if(!cnt[j]) continue;
            if(__gcd(i,j)!=1){
                x+=(cnt[j]*cnt[i]);
            }
        }
        res+=(x + y);
    }
    cout<<res<<endl;

    return 0;
}


