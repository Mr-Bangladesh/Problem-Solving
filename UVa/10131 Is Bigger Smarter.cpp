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

struct ff{
    int first,second,idx;
    ff(int a,int b,int c){
        first=a; second=b; idx=c;
    }
};
bool cmp(ff a,ff b){
    return a.first<b.first;
}
int main()
{
    //freopen("1.txt","r",stdin);
    vector< ff > v;
    v.pb(ff(0,0,0));
    int x,y;
    int i=1;
    while(scanf("%d %d",&x,&y)!=EOF){
        v.pb(ff(x,y,i++));
    }
    sort(v.begin(),v.end(),cmp);
    int n=v.size()-1;
    int LIS=1,L[n+2]={0};
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(v[i].first<v[j].first && v[i].second>v[j].second){
                if(L[j]<L[i]+1){
                    L[j]=L[i]+1;
                    LIS=max(LIS,L[j]+1);
                }
            }
        }
    }
    LIS--;
    vector<int> ans;
    for(int i=n;i>=1;i--){
        if(L[i]==LIS){
            ans.pb(v[i].idx);
            LIS--;
        }
    }
    printf("%d\n",ans.size());
    reverse(ans.begin(),ans.end());
    for(int it:ans){
        printf("%d\n",it);
    }

    return 0;
}


