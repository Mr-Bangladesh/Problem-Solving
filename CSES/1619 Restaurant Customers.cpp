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
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
///order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
    int n;
    int x,y;
    cin>>n;
    vector< pair<int,int> > v;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    sort(v.begin(),v.end());
    oset< pair<int,int> > s;
    int ans=1;
    for(int i=0;i<n;i++){
        int x=v[i].first; int y=v[i].second;
        s.insert(mp(y,i+1));
        //for(auto a:s) cout<<a.first<<" "; cout<<endl;
        int j=s.order_of_key(mp(x+1,0));
        ///cout<<i<<" "<<x<<" "<<y<<" "<<j<<endl;
        int cur=s.size()-j;
        ans=max(ans,cur);
    }
    cout<<ans<<endl;

    return 0;
}

