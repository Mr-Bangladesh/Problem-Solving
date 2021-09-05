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
int n,row[15];
bitset<30> rw,ld,rd;
int idx,a,b;
void backtrack(int c){
    if(c==n){
        if(row[b]==a){
            printf("%2d     ",idx++);
            for(int i=0;i<n;i++){
                printf(" %d",row[i]+1);
            }
            printf("\n");
        }
        return;
    }
    for(int r=0;r<n;r++){
        if(!rw[r] && !ld[r-c+n-1] && !rd[r+c]){
            rw[r]=ld[r-c+n-1]=rd[r+c]=true;
            row[c]=r;
            backtrack(c+1);
            rw[r]=ld[r-c+n-1]=rd[r+c]=false;
        }
    }
}
int main()
{
    n=8;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        a--; b--;
        memset(row,0,sizeof(row));
        rw.reset();ld.reset();rd.reset();
        idx=1;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if(t) printf("\n");
    }

    return 0;
}


