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

vector<int> LIS(vector<int> v,int n){
    vector<int> lis,idx,previdx;
    for(int i=0;i<n;i++){
        int pos=lower_bound(lis.begin(),lis.end(),v[i])-lis.begin();
        if(pos==lis.size()){
            lis.pb(v[i]);
            idx.pb(i);
        }
        else{
            lis[pos]=v[i];
            idx[pos]=i;
        }
        previdx.pb(pos?idx[pos-1]:-1);
    }
    vector<int> ans;
    int cur=idx.back();
    while(cur!=-1){
        ans.pb(v[cur]);
        cur=previdx[cur];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    vector<int> lis,idx,previdx,v;
    int x;
    while(scanf("%d",&x)!=EOF){
        v.pb(x); //cout<<x<<endl;
    }
    n=v.size();
    vector<int> ans=LIS(v,n);
    printf("%d\n-\n",ans.size());
    for(int x:ans) printf("%d\n",x);

    return 0;
}

