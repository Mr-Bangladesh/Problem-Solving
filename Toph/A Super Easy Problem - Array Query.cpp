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
        ll n;
        scanf("%lld",&n);
        ll a[n+2];
        ll neg[n+2]={0},negcnt[n+2]={0};
        ll pos[n+2]={0},poscnt[n+2]={0};
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            if(a[i]<0){
                neg[i]=neg[i-1]+abs(a[i]);
                pos[i]=pos[i-1];
                negcnt[i]=negcnt[i-1]+1;
                poscnt[i]=poscnt[i-1];
            }
            else{
                pos[i]=pos[i-1]+a[i];
                neg[i]=neg[i-1];
                poscnt[i]=poscnt[i-1]+1;
                negcnt[i]=negcnt[i-1];
            }
        }
        ll q;
        scanf("%lld",&q);
        ll l,r,x;
        printf("Case %d:\n",cs);
        while(q--){
            scanf("%lld %lld %lld",&l,&r,&x);
            ll a=(poscnt[r]-poscnt[l-1])*x;
            ll b=(negcnt[r]-negcnt[l-1])*x;
            ll p=neg[r]-neg[l-1];
            ll q=pos[r]-pos[l-1];
            //cout<<a<<" "<<b<<endl;
            ll ans;
            if(x<0){
                ans=abs(b+p)+abs(a-q-(poscnt[r]-poscnt[l-1]));
            }
            else{
                ans=abs(b+p+(negcnt[r]-negcnt[l-1]))+abs(a-q);
            }
            printf("%lld\n",ans);
        }
    }

    return 0;
}


