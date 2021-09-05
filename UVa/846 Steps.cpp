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
vector< pair<ll,ll> > v;
void init(){
    ll i=2;
    ll lim=1LL<<31;
    ll sum=0;
    v.pb(mp(3,3));
    while(sum<=lim){
        ll x=(i*(i+1))/2;
        v.pb(mp(x+x-i,i+i-1));
        v.pb(mp(x+x,i+i));
        sum=x+x;
        i++;
    }
}

struct compare {
    bool operator()(const pair<ll, ll>& value,
                                const ll& key)
    {
        return (value.first < key);
    }
    bool operator()(const ll& key,
                    const pair<ll, ll>& value)
    {
        return (key < value.first);
    }
};


int main()
{
    init();
    //cout<<v.size()<<endl;
//    for(auto it:v){
//        cout<<it.first<<" "<<it.second<<endl;
//    }
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ll x=b-a;
        if(x<=3){
            printf("%lld\n",x);
        }
        else{
            int i=lower_bound(v.begin(),v.end(),x,compare())-v.begin();
            printf("%lld\n",v[i].second);
        }

    }

    return 0;
}


