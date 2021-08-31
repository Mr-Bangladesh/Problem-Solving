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

int main()
{
    int n;
    cin>>n;
    int a[n+1];

    map<int, vector<int> > v;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]].pb(i);
    }

    int cur=n,res=1;
    for(int i=n-1;i>=1;i--){
        auto it=lower_bound(v[a[i]].begin(),v[a[i]].end(),i+1);
        if(it==v[a[i]].end()){
            res=max(res,cur-i+1);
        }
        else{
            int x=*it;
            res=max(res,cur-i);
            cur=min(cur,x-1);
        }
        //cout<<i<<" "<<cur<<" "<<res<<endl;
    }

    cout<<res<<endl;



    return 0;
}


