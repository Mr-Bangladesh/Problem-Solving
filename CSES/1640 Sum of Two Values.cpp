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

map<int,vector<int> > cnt;

int main()
{
    int n,x;
    cin>>n>>x;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]].pb(i);
    }
    //sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int cur=x-a[i];
        if(cur==a[i]){
            if(cnt[cur].size()>1){
                cout<<cnt[cur][0]<<" "<<cnt[cur][1]<<endl;
                return 0;
            }
        }
        else{
            if(cnt[cur].size()){
                cout<<i<<" "<<cnt[cur][0]<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}


