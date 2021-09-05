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
map<char,int> val;
int main()
{
    val['B']=1;
    val['F']=1;
    val['P']=1;
    val['V']=1;
    val['C']=2;
    val['G']=2;
    val['J']=2;
    val['K']=2;
    val['Q']=2;
    val['S']=2;
    val['X']=2;
    val['Z']=2;
    val['D']=3;
    val['T']=3;
    val['L']=4;
    val['M']=5;
    val['N']=5;
    val['R']=6;
    string s;
    while(cin>>s){
        int len=s.length();
        string ans="";
        if(val[s[0]]) ans+=(val[s[0]]+48);
        //8cout<<s[0]<<" "<<val[s[0]]<<endl;
        for(int i=1;i<len;i++){
            if(val[s[i]]==val[s[i-1]]) continue;
            if(val[s[i]]) ans+=(val[s[i]]+48);
        }
        cout<<ans<<endl;
    }

    return 0;
}

