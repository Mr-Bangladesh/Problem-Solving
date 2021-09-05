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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    int n;
    string s;
    cin>>n>>s;
    vector<int> g[27];
    for(int i=0;i<n;i++){
        g[s[i]-96].pb(i);
    }
    int q;
    string a;
    cin>>q;
    while(q--){
        cin>>a;
        int len=a.length();
        int last=-1;
        bool check=true;
        for(int i=0;i<len;i++){
            //cout<<last<<endl;
            char c=a[i];
            auto it=upper_bound(g[c-96].begin(),g[c-96].end(),last);
            if(it==g[c-96].end()){
                check=false; break;
            }
            int idx=it-g[c-96].begin();
            last=g[c-96][idx];
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}


