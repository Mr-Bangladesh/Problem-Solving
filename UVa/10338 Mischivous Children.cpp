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
    ll a[30];
    a[0]=1;
    for(int i=1;i<=27;i++){
        a[i]=a[i-1]*i;
    }
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int len=s.length();
        int cnt[30]={0};
        for(int i=0;i<len;i++){
            cnt[s[i]-64]++;
        }
        ll ans=a[len];
        //cout<<s<<" "<<len<<" "<<ans<<endl;
        for(int i=1;i<=26;i++){
            ans/=a[cnt[i]];
        }
        printf("Data set %d: %lld\n",cs++,ans);
    }

    return 0;
}


