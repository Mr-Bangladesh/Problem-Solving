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
    ll n,a,b,c,d;
    cin>>n;
    vector<ll> v1,v2,v3,v4;
    for(ll i=1;i<=n;i++){
        cin>>a>>b>>c>>d;
        v1.pb(a); v2.pb(b); v3.pb(c); v4.pb(d);
    }

    vector<ll> v;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++) v.pb(v1[i]+v2[j]);
    }
    sort(v.begin(),v.end());
    //for(int x:v) cout<<x<<" "; cout<<endl;
    ll cnt=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            ll x=v3[i]+v4[j];
            //cout<<x<<endl;
            if(binary_search(v.begin(),v.end(),-x)){
                a=upper_bound(v.begin(),v.end(),-x)-v.begin();
                b=lower_bound(v.begin(),v.end(),-x)-v.begin();
                cnt+=(a-b);
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}


