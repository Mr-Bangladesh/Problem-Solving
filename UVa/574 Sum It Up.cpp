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
int t,n,a[15];
set< vector<int> > ans;
void backtrack(int idx,int sum,int mask){
    //cout<<idx<<" "<<sum<<" "<<mask<<endl;
    if(sum==t){
        vector<int> tmp;
        for(int i=1;i<=n;i++){
            if(mask&(1<<i)) tmp.pb(a[i]);
        }
        ans.insert(tmp);
        //cout<<idx<<" "<<sum<<" "<<mask<<endl;
    }
    if(idx>n || sum>t) return;
    if(sum+a[idx]<=t){
        backtrack(idx+1,sum+a[idx],mask|(1<<idx));
    }
    backtrack(idx+1,sum,mask);
}
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    while(scanf("%d %d",&t,&n),n){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1,cmp);
        backtrack(1,0,0);
        vector< vector<int> > tmp;
        for(auto it:ans) tmp.pb(it);
        reverse(tmp.begin(),tmp.end());
        printf("Sums of %d:\n",t);

        if(tmp.size()==0){
            printf("NONE\n");
            continue;
        }

        for(auto it:tmp){
            printf("%d",it.front());
            for(int i=1;i<it.size();i++){
                printf("+%d",it[i]);
            }
            printf("\n");
        }

        ans.clear();

    }

    return 0;
}

