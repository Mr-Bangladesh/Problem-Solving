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
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    ll ans=(n-m+1)*m;
    ll cnt[n+3][30];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        cnt[i+1][a[i]-96]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++){
            cnt[i][j]+=cnt[i-1][j];
        }
    }

    for(int i=0;i<m;i++){
        x=cnt[n-(m-i-1)][b[i]-96]-cnt[i][b[i]-96];
        //cout<<b[i]<<" "<<x<<endl;
        ans-=x;
    }
    cout<<ans<<endl;

    return 0;
}

