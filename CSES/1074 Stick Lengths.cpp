/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
///order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

ll f(ll a[],int n,ll k){
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=(abs(a[i]-k));
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    ll a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    if(n%2){
        ll x=a[(n+1)/2];
        cout<<f(a,n,x)<<endl;
    }
    else{
        ll i=a[n/2];
        ll j=a[n/2 +1];
        ll x=(i+j)/2;
        cout<<min(f(a,n,x),f(a,n,x+1))<<endl;
    }

    return 0;
}


