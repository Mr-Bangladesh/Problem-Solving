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
int n,a[17],cnt;
int mark[17],isprime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};
void backtrack(int idx){
    //cout<<idx<<endl;
    if(idx>n){
        for(int i=1;i<=n;i++){
            printf("%d",a[i]);
            if(i<n) printf(" ");
        }
        printf("\n");
        return;
    }
    for(int i=2;i<=n;i++){
        if(!mark[i]){
            //cout<<idx<<" "<<i<<endl;
            if(idx==n && isprime[a[idx-1]+i] && isprime[1+i]){
                mark[i]=1;
                a[idx]=i;
                backtrack(idx+1);
                mark[i]=0;
            }
            else if(idx<n && isprime[a[idx-1]+i]){
                mark[i]=1;
                a[idx]=i;
                backtrack(idx+1);
                mark[i]=0;
            }
        }
    }
}
int main()
{
    int cs=1,first=0;
    while(scanf("%d",&n)!=EOF){
        if(first){
            printf("\n");
        }
        first=1;
        a[1]=1;
        mark[1]=1;
        printf("Case %d:\n",cs++);
        backtrack(2);
        memset(a,0,sizeof(a));
        memset(mark,0,sizeof(mark));
    }

    return 0;
}

