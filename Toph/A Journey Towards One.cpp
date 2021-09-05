/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
ll dp[1000005];
int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    dp[1]=0;
    dp[2]=1;
    dp[3]=2;
    for(int i=4;i<=1000000;i+=2){
        dp[i]=dp[i/2]+1;
        dp[i-1]=min(dp[i-2],dp[i])+1;
    }

//    for(int i=1;i<=1000000;i++){
//        cout<<i<<" "<<dp[i]<<endl;
//    }

    cin>>t;
    while(t--){
        cin>>n;
        cout<<dp[n]<<endl;
    }

    return 0;
}

