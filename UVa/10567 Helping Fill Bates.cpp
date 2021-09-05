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
map<char,vector<int> > g;
int main()
{
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        g[s[i]].pb(i);
    }

    int q;
    scanf("%d",&q);
    while(q--){
        cin>>s;
        int len=s.length();
        int cur=0,st=0;
        bool check=true;
        if(!g[s[0]].size()){
            check=false;
        }
        else{
            cur=g[s[0]].front();
            st=cur;
        }
        for(int i=1;i<len;i++){
            auto it=lower_bound(g[s[i]].begin(),g[s[i]].end(),cur+1);
            int idx=it-g[s[i]].begin();
            if(it==g[s[i]].end()){
                check=false;
                break;
            }
            cur=g[s[i]][idx];
            //cout<<s[i]<<" "<<cur<<endl;
        }
        if(check){
            printf("Matched %d %d\n",st,cur);
        }
        else{
            printf("Not matched\n");
        }
        //cout<<st<<" "<<cur<<" "<<check<<endl;
    }

    return 0;
}

///aaaabbbaaaaacccdbbbbddd
///bbaacddbdd
