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
    while(cin>>s){
        int len=s.length();
        deque<string> ans;
        for(int i=0;i<len;i++){
            string tmp;
            for(int j=i;j<len;j++){
                if(s[j]=='[' || s[j]==']'){
                    i=j;
                    break;
                }
                tmp+=s[j];
                if(j==len-1){
                    i=j; break;
                }
            }
            if(s[i]=='[') ans.pb(tmp);
            else if(s[i]==']') ans.push_front(tmp);
            else ans.pb(tmp);
            //cout<<i<<" "<<tmp<<endl;
        }
        for(string a:ans) cout<<a; cout<<endl;
    }

    return 0;
}

