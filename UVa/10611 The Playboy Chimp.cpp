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
    int n,x,q;
    vector<int> v;
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        v.pb(x);
        mx=max(mx,x);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        int left,right;
        if(x>mx){
            right=-1;
            left=mx;
        }
        else if(x==mx){
            right=-1;
            int i=lower_bound(v.begin(),v.end(),x)-v.begin();
            i--;
            if(i<0) left=-1;
            else left=v[i];
        }
        else{
            if(binary_search(v.begin(),v.end(),x)){
                int i=lower_bound(v.begin(),v.end(),x)-v.begin();
                i--;
                if(i<0) left=-1;
                else left=v[i];
                int j=upper_bound(v.begin(),v.end(),x)-v.begin();
                if(j==n) right=-1;
                else right=v[j];
            }
            else{
                int j=lower_bound(v.begin(),v.end(),x)-v.begin();
                right=v[j];
                if(j==0) left=-1;
                else left=v[j-1];
            }
        }
        if(left==-1) printf("X ");
        else printf("%d ",left);
        if(right==-1) printf("X");
        else printf("%d",right);
        printf("\n");

    }

    return 0;
}

