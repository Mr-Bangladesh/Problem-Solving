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

vector<int> f(vector<int> v,int n){
    vector<int> lis,len;
    for(int i=0;i<n;i++){
        int pos=lower_bound(lis.begin(),lis.end(),v[i])-lis.begin();
        if(pos==lis.size()){
            lis.pb(v[i]);
        }
        else{
            lis[pos]=v[i];
        }
        len.pb(pos+1);
    }
    return len;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        vector<int> v;
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            v.pb(x);
        }
        vector<int> lis=f(v,n);
        reverse(v.begin(),v.end());
        vector<int> lds=f(v,n);
        //reverse(lds.begin(),lds.end());

        int ans=0;
        for(int i=0;i<n;i++){
            int x=min(lis[i],lds[n-i-1]);
            ans=max(ans,x*2-1);
        }
        printf("%d\n",ans);
    }

    return 0;
}


