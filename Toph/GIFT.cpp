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
int dp[101][10002][2],dir[101][10002][2];
int N,M;
int a[101],b[101];
int f(int idx,int sum,int ikri){
    //cout<<idx<<" "<<sum<<" "<<ikri<<endl;

    if(idx>N && sum==M && ikri==1) return 1;
    if(idx>N || sum>M) return 0;
    if(dp[idx][sum][ikri]!=-1) return dp[idx][sum][ikri];
    int x=0,y=0,z=0;
    if(a[idx]+sum<=M){
        x=f(idx+1,a[idx]+sum,ikri); //cout<<"first "<<idx<<" "<<sum<<" "<<ikri<<endl;
    }
    if(b[idx]+sum<=M){
        y=f(idx+1,b[idx]+sum,ikri); //cout<<"second "<<idx<<" "<<sum<<" "<<ikri<<endl;
    }
    if(ikri==0){
        z=f(idx+1,sum,1); //cout<<"no "<<idx<<" "<<sum<<" "<<ikri<<endl;
    }
    if(x==1){
        dp[idx][sum][ikri]=x;
        dir[idx][sum][ikri]=1;
    }
    else if(y==1){
        dp[idx][sum][ikri]=y;
        dir[idx][sum][ikri]=2;
    }
    else if(z==1){
        dp[idx][sum][ikri]=z;
        dir[idx][sum][ikri]=0;
    }
    else{
        dp[idx][sum][ikri]=0;
    }
    return dp[idx][sum][ikri];
}
vector<int> v;
void print(int idx,int sum,int ikri){
    if(dir[idx][sum][ikri]==-1) return;
    //cout<<idx<<" "<<sum<<" "<<ikri<<endl;
    if(dir[idx][sum][ikri]==1){
        v.pb(1);
        print(idx+1,sum+a[idx],ikri);
    }
    else if(dir[idx][sum][ikri]==2){
        v.pb(2);
        print(idx+1,sum+b[idx],ikri);
    }
    else{
        v.pb(0);
        print(idx+1,sum,1);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        memset(dp,-1,sizeof(dp));
        memset(dir,-1,sizeof(dir));
        v.clear();
        N=n; M=m;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i],&b[i]);
        }
        int x=f(1,0,0);
        if(!x){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        print(1,0,0);
        for(int x:v){
            printf("%d ",x);
        }
        printf("\n");
    }

    return 0;
}


