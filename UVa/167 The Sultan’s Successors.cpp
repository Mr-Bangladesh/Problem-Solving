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
int row[8],a[10][10],ans;
bool check(int r,int c){
    for(int j=0;j<c;j++){
        if(row[j]==r || (abs(row[j]-r)==abs(j-c))){
            return false;
        }
    }
    return true;
}
void backtrack(int c){
    if(c==8){
        int sum=0;
        for(int i=0;i<8;i++){
            sum+=a[row[i]+1][i+1];
        }
        ans=max(ans,sum);
        return;
    }
    for(int r=0;r<8;r++){
        if(check(r,c)){
            row[c]=r; backtrack(c+1);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                scanf("%d",&a[i][j]);
            }
        }
        backtrack(0);
        printf("%5d\n",ans);
        memset(row,0,sizeof(row));
        ans=0;
    }

    return 0;
}

