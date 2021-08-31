#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

ll F(string a,string b,ll n,ll m){
    ll dp[n+4][m+5];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
    }

    return dp[n][m];

}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;

    while(t--){
        string a,b;
        cin>>a>>b;
        ll ans=F(a,b,a.length(),b.length());
        cout<<ans<<endl;
    }

    return 0;
}



