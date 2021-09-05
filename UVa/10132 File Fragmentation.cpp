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
    //freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        string s;
        vector<string> v;
        while(getline(cin,s)){
            if(s=="") break;
            v.pb(s);
        }
        map<string,int> cnt;
        string ans=""; int mx=0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                string a; a+=(v[i]+v[j]);
                string b; b+=(v[j]+v[i]);
                cnt[a]++;
                cnt[b]++;
                if(cnt[a]>mx){
                    mx=cnt[a];
                    ans=a;
                }
                if(cnt[b]>mx){
                    mx=cnt[b];
                    ans=b;
                }
            }
        }
        cout<<ans<<endl;
        if(t) cout<<endl;
    }

    return 0;
}

