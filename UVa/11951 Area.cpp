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

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        ll n,m,K;
        scanf("%lld %lld %lld",&n,&m,&K);
        ll a[n+2][m+2];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%lld",&a[i][j]);
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i>1) a[i][j]+=a[i-1][j];
                if(j>1) a[i][j]+=a[i][j-1];
                if(i>1 && j>1) a[i][j]-=a[i-1][j-1];
            }
        }
        ll ans=0,ans2=INF;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //cout<<"start "<<i<<" "<<j<<endl;
                for(int k=i;k<=n;k++){
                    for(int l=j;l<=m;l++){
                        //cout<<"end "<<k<<" "<<l<<endl;
                        ll sum=a[k][l];
                        if(i>1) sum-=a[i-1][l];
                        if(j>1) sum-=a[k][j-1];
                        if(i>1 && j>1) sum+=a[i-1][j-1];

                        if(sum<=K){
                            //cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<sum<<endl;
                            ll x=k-i+1;
                            ll y=l-j+1;
                            if(x*y>ans){
                                ans=x*y;
                                ans2=sum;
                            }
                            else if(x*y==ans){
                                ans2=min(ans2,sum);
                            }
                        }
                    }
                }
            }
        }
        if(ans2==INF) ans2=0;
        printf("Case #%d: %lld %lld\n",cs,ans,ans2);
    }

    return 0;
}


