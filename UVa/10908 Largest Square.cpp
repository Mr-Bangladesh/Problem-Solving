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
    int t;
    scanf("%d",&t);
    int n,m,q;
    while(t--){
        scanf("%d %d %d",&n,&m,&q);
        string s[n+2];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        printf("%d %d %d\n",n,m,q);
        while(q--){
            int r,c;
            scanf("%d %d",&r,&c); r++;c++;
            int left=c-1,right=m-c,up=r-1,down=n-r;
            int mx=min(left,min(right,min(up,down)));
            int ans=0;
            for(int len=0;len<=mx;len++){
                int x1=r-len,y1=c-len,x2=r+len,y2=c+len;
                char ch=s[x1-1][y1-1]; bool check=true;
                for(int i=x1-1;i<x2;i++){
                    for(int j=y1-1;j<y2;j++){
                        if(s[i][j]!=ch){
                            check=false; break;
                        }
                    }
                }
                if(check){
                    ans=max(ans,len*2+1);
                }
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}

