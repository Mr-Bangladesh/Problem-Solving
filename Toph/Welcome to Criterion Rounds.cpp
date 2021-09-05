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
ll dp[100005];
int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    dp[1]=0;
    dp[2]=0;
    for(int i=3;i<=100000;i++){
        x=sqrt(i);
        ll cnt=0;
        for(int j=2;j<=x;j++){
            n=i;
            ll r1=n%j; n/=j;
            ll r2=n%j;
            if(r2==0 && r1>0) cnt++;
        }
        dp[i]=cnt;
    }

    //for(int i=1;i<=100000;i++) cout<<i<<" "<<dp[i]<<endl;

    cin>>q;
    for(ll cs=1;cs<=q;cs++){
        scanf("%lld",&n);
        printf("Query %lld: %lld\n",cs,dp[n]);
    }

    return 0;
}

