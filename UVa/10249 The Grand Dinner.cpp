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
    int n,m;
    while(scanf("%d %d",&n,&m),n||m){
        int a[n+1],b[m+1];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        vector< pair<int,int> > v;
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
            v.pb(mp(b[i],i));
        }
        sort(v.rbegin(),v.rend());
        vector<int> ans[n+1];
        bool check=true;
        for(int i=1;i<=n;i++){
            int x=a[i];
            for(int j=0;j<m;j++){
                if(v[j].first && x>0){
                    ans[i].pb(v[j].second);
                    x--;
                    v[j].first--;
                    //cout<<"taken "<<i<<" "<<j<<" "<<b[j]<<endl;
                }
            }
            //for(int j=0;j<m;j++) cout<<v[j].first<<" "; cout<<endl;
            if(x){
                check=false; break;
            }
        }
        if(check){
            printf("1\n");
            for(int i=1;i<=n;i++) sort(ans[i].begin(),ans[i].end());
            for(int i=1;i<=n;i++){
                for(int x:ans[i]){
                    printf("%d ",x);
                }
                printf("\n");
            }
        }
        else printf("0\n");
    }

    return 0;
}

