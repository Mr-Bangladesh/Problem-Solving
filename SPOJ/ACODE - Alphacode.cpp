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
int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    char s[5002];
    while(scanf("%s",s)){
        if(s[0]=='0') break;
        ll N=strlen(s);
        ll dp[50005];
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        for(int i=2;i<=N;i++){
            x=(s[i-2]-48)*10+s[i-1]-48;
            if(x>=10 && x<=26) dp[i]+=dp[i-2];
            if(s[i-1]!='0') dp[i]+=dp[i-1];
        }
        printf("%lld\n",dp[N]);
    }

    return 0;
}


