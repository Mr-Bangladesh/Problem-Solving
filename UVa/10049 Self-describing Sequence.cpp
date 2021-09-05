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
    vector<ll> v;
    ll sum=0;
    for(ll i=1;i<=10000;i++){
        ll x=i*i;
        sum+=x;
        v.pb(sum);
    }
    sum=0;
    vector<ll> u;
    for(ll i=1;i<=100000;i++){
        sum+=i;
        u.pb(sum);
    }
    ll n;
    while(scanf("%lld",&n),n){
        if(n==1){
            printf("1\n");
            continue;
        }
        ll x=lower_bound(v.begin(),v.end(),n)-v.begin();
        ll g=n-v[x-1];
        ll sq=sqrt(v[x]-v[x-1]);
        //cout<<v[x]<<" "<<v[x-1]<<" "<<g<<" "<<sq<<endl;
        ll d=g/sq;
        ll r=g%sq;
        ll l=(sq*(sq-1))/2; l++;
        if(r) d++;
        cout<<l<<" "<<d<<endl;
        printf("%lld\n",l+d-1);
    }

    return 0;
}


