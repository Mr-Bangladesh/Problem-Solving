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
    string s;
    int cs=1;
    while(cin>>s){
        if(s=="end") break;
        int len=s.length();
        set<int> used;
        for(int i=0;i<len;i++){
            if(used.size()==0){
                used.insert(s[i]-64);
                continue;
            }
            auto it=used.lower_bound(s[i]-64);
            if(it==used.end()){
                used.insert(s[i]-64);
            }
            else{
                used.erase(it);
                used.insert(s[i]-64);
            }

            //for(auto it:used) cout<<it<<" "; cout<<endl;
        }
        printf("Case %d: %d\n",cs++,used.size());
    }

    return 0;
}

