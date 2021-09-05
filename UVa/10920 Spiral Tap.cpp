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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    vector<ll> v;
    v.pb(0);
    for(ll i=1;i<=100000;i+=2){
        v.pb(i*i);
    }
    //for(int x:v) cout<<x<<" "; cout<<endl;
    ll n,k;
    while(scanf("%lld %lld",&n,&k)){
        if(n==0 && k==0) break;
        ll c1=n/2 +1; ll c2=c1;
        //cout<<n<<" "<<k<<endl;
        ll id=lower_bound(v.begin(),v.end(),k)-v.begin();
        ll x=c1+id-1;ll y=x;
        ll sq=sqrt(v[id]);
        int a,b,c,d;
        a=b=c=sq-1;
        d=max(0,a-1);
        int st=v[id];
        int gap=st-k;
        y-=min(a,gap);
        st-=min(a,gap);
        //cout<<x<<" "<<y<<endl;

        gap=st-k;
        x-=min(b,gap);
        st-=min(b,gap);
        //cout<<x<<" "<<y<<endl;

        gap=st-k;
        y+=min(c,gap);
        st-=min(c,gap);
        //cout<<x<<" "<<y<<endl;

        gap=st-k;
        x+=min(d,gap);
        st-=min(d,gap);

        //cout<<x<<" "<<y<<endl;
        //cout<<c1<<" "<<c2<<" "<<x<<" "<<y<<" "<<id<<" "<<v[id]<<endl;

        printf("Line = %lld, column = %lld.\n",y,x);
    }

    return 0;
}

