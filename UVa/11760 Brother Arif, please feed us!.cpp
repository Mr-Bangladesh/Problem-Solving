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
ll fx4[]={0,1,-1,0,0}; ll fy4[]={0,0,0,1,-1};

int main()
{
    int r,c,n,cs=1;
    while(scanf("%d %d %d",&r,&c,&n)){
        if(r==0 && c==0 && n==0) break;
        int row[r+1]={0},col[c+1]={0};
        int x,y;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&x,&y);
            row[x]=col[y]=1;
        }
        scanf("%d %d",&x,&y);
        bool check=false;
        for(int i=0;i<5;i++){
            int u=x+fx4[i],v=y+fy4[i];
            if(u>=0 && u<r && v>=0 && v<c){
                if(row[u]==0 && col[v]==0){
                    check=true; break;
                }
            }
        }
        if(check){
            printf("Case %d: Escaped again! More 2D grid problems!\n",cs++);
        }
        else{
            printf("Case %d: Party time! Let's find a restaurant!\n",cs++);
        }
    }

    return 0;
}

