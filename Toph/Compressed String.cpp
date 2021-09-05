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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len=s.length();
        int b=-1;
        for(int i=0;i<len;i++){
            if(s[i]=='b'){
                b=i;
            }
        }
        if(b==-1){
            cout<<'a'<<endl;
        }
        else if(b==len-1){
            cout<<'b'<<endl;
        }
        else{
            cout<<"ba"<<endl;
        }
    }

    return 0;
}


