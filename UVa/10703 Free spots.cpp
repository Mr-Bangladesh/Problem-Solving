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
    int w,h,n;
    while(scanf("%d %d %d",&w,&h,&n)){
        if(w==0 && h==0 && n==0) break;
        int mark[w+1][h+1];
        memset(mark,0,sizeof(mark));
        for(int i=1;i<=n;i++){
            int x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            int a=x2,b=y1,c=x1,d=y2;
            if(a>c){
                int x=a,y=b;
                a=c; b=d;
                c=x; d=y;
            }
            cout<<"corner "<<a<<" "<<b<<"   "<<c<<" "<<d<<endl;
            for(int j=a;j<=c;j++){
                for(int k=b;k<=d;k++){
                    mark[j][k]=1;
                    cout<<"marked "<<j<<" "<<k<<endl;
                }
            }
            for(int j=x1;j<=x2;j++){
                for(int k=y1;k<=y2;k++){
                    mark[j][k]=1;
                    cout<<"marked "<<j<<" "<<k<<endl;
                }
            }
        }
        int cnt=w*h;
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                cnt-=mark[i][j];
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}

