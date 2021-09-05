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
    ll a[n+1];
    unordered_map<ll,pair<ll,ll> > idx;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        idx[a[i]].first=n+1; idx[a[i]].second=0;
    }
    for(int i=1;i<=n;i++){
        idx[a[i]].first=min(idx[a[i]].first,i);
        idx[a[i]].second=max(idx[a[i]].second,i);
    }
    ll ans=0;
    for(auto it:idx){
        auto p=it.second;
        ans=max(ans,p.second-p.first+1);
    }
    cout<<ans<<endl;


    return 0;
}


