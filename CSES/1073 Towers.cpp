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
    int n,x;
    cin>>n;
    multiset<int>s;
    for(int i=0;i<n;++i)
    {
    	cin>>x;
    	auto it=s.upper_bound(x);
    	//cout<<*it<<endl;
    	if(it==s.end())s.insert(x);
    	else
    	{
    		s.erase(it);
    		s.insert(x);
        }
        //cout<<"set"<<endl;for(auto it:s) cout<<it<<" "; cout<<endl;
    }
    cout<<s.size()<<endl;

    return 0;
}


