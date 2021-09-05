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
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        ll n,s;
        scanf("%lld %lld",&n,&s);
        ll a[n+1];
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+n+1);
        ll l=1,r=a[n];
        ll ans=0;
        while(l<=r){
            ll mid=(l+r)/2;
            ll cnt=0;
            for(int i=1;i<=n;i++){
                cnt+=(a[i]/mid);
            }
            if(cnt>=s){
                ans=max(ans,mid);
            }
            if(cnt<s){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        printf("Case %d: %lld\n",cs,ans);
    }

    return 0;
}


