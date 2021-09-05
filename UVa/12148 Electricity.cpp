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
#define EPS 1e-9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool leap(int n){
    if(n%400==0) return 1;
    if(n%4==0){
        if(n%100) return 1;
        else return 0;
    }
    else return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
        int d[n+1],m[n+1],y[n+1],c[n+1];
        for(int i=1;i<=n;i++){
            scanf("%d %d %d %d",&d[i],&m[i],&y[i],&c[i]);
        }
        int ans=0,cnt=0;
        for(int i=2;i<=n;i++){
            int d1=d[i]-1;
            int m1=m[i]; int y1=y[i];
            if(d1==0){
                if(m1>1){
                    if(m1==3 && leap(y1)){
                        d1=29;
                        m1=2;
                    }
                    else{
                        m1--;
                        d1=mon[m1];
                    }
                }
                else{
                    m1=12;
                    d1=31;
                    y1--;
                }
            }
            //cout<<d1<<" "<<m1<<" "<<y1<<" "<<d[i-1]<<" "<<m[i-1]<<" "<<y[i-1]<<endl;
            if(d[i-1]==d1 && m[i-1]==m1 && y[i-1]==y1){
                //cout<<d1<<" "<<m1<<" "<<y1<<endl;
                cnt++;
                ans+=(c[i]-c[i-1]);
            }
        }
        printf("%d %d\n",cnt,ans);
    }

    return 0;
}


