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
    while(scanf("%d",&n),n){
        int a[n+2][n+2];
        a[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int row[n+2]={0},col[n+2]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                row[i]+=a[i][j];
                col[j]+=a[i][j];
            }
        }
        bool check=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(row[i]%2==1 || col[i]%2==1){
                    check=false; break;
                }
            }
        }
        int cnt=0,x=0,y=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(row[i]%2==1 && col[j]%2==1){
                    cnt++;
                    x=i; y=j;
                    break;
                }
            }
        }
        if(check){
            printf("OK\n");
            continue;
        }
        if(a[x][y]==1){
            a[x][y]=0;
            row[x]--;
            col[y]--;
        }
        else{
            a[x][y]=1;
            row[x]++;
            col[y]++;
        }

        //cout<<x<<" "<<y<<endl;

        check=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(row[i]%2==1 || col[i]%2==1){
                    check=false; break;
                }
            }
        }
        if(check){
            printf("Change bit (%d,%d)\n",x,y);
        }
        else{
            printf("Corrupt\n");
        }

    }

    return 0;
}

