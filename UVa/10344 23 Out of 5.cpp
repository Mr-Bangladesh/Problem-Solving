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
int n;
vector<int> a;
bool backtrack(int idx,int sum){
    //if(sum>23) return false;
    if(idx==n){
        //cout<<idx<<" "<<sum<<endl;
        if(sum==23) return true;
        else return false;
    }
    int x=backtrack(idx+1,sum+a[idx]);
    int y=backtrack(idx+1,sum-a[idx]);
    int z=backtrack(idx+1,sum*a[idx]);
    return x|y|z;
}

int main()
{
    n=5;
    while(1){
        int s=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            a.pb(x);
            s+=x;
        }
        if(!s) break;
        bool check=false;
        do{
            //for(int x:a) //cout<<x<<" "; cout<<endl;
            if(backtrack(1,a[0])){
                printf("Possible\n");
                check=true;
                break;
            }
        }
        while(next_permutation(a.begin(),a.end()));

        a.clear();

        if(!check){
            printf("Impossible\n");
        }

    }

    return 0;
}

