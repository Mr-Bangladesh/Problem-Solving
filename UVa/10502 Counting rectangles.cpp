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
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        int a[n+1][m+1];
        string s[n+1];
        for(int i=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<m;j++){
                a[i+1][j+1]=s[i][j]-48;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i>1) a[i][j]+=a[i-1][j];
                if(j>1) a[i][j]+=a[i][j-1];
                if(i>1 && j>1) a[i][j]-=a[i-1][j-1];
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=i;k<=n;k++){
                    for(int l=j;l<=m;l++){
                        int sum=a[k][l];
                        if(i>1) sum-=a[i-1][l];
                        if(j>1) sum-=a[k][j-1];
                        if(i>1 && j>1) sum+=a[i-1][j-1];
                        int total=(abs(k-i)+1)*(abs(l-j)+1);
                        //cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<sum<<" "<<total<<endl;
                        if(sum==total) cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}

