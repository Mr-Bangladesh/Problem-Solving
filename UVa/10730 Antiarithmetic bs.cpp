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
    int n;
    while(scanf("%d:",&n),n){
        int a[n+2];
        int idx[n+2]={0},mark[n+2]={0};
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            idx[a[i]]=i;
            mark[a[i]]=1;
        }
        bool check=true;
        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                if(a[j]<a[i]){
                    int diff=a[i]-a[j];
                    //cout<<a[j]<<" "<<a[i]<<" "<<a[i]+diff<<" "<<mark[a[i]+diff]<<" "<<idx[a[i]+diff]<<endl;
                    if(mark[a[i]+diff]==1){
                        //cout<<a[j]<<" "<<a[i]<<" "<<a[i]+diff<<endl;
                        if(idx[a[i]+diff]>i){
                            //cout<<a[j]<<" "<<a[i]<<" "<<a[i]+diff<<endl;
                            check=false; break;
                        }
                    }
                }
            }
            if(!check) break;
        }
        if(check) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}

