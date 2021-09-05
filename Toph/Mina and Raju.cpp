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
ll bigmod(ll B,ll P,ll M){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=bigmod(B,P/2,M);
        return ((R%M)*(R%M))%M;
    }
    else{
        ll R=bigmod(B,P-1,M);
        return ((R%M)*(B%M))%M;
    }
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    ll a[105];
    a[0]=1;
    for(int i=1;i<=100;i++){
        a[i]=(a[i-1]*i)%MOD;
    }

    cin>>t;
    while(t--){
        cin>>n>>m>>p>>q>>k;
        ll ans=0;
        for(int i=p;i<=k;i++){
            int j=k-i;
            if(i<=n && j<=m && j>=q){
                x=(a[n]*bigmod((a[i]*a[n-i])%MOD,MOD-2,MOD))%MOD;
                y=(a[m]*bigmod((a[j]*a[m-j])%MOD,MOD-2,MOD))%MOD;
                ans=(ans+(x*y)%MOD)%MOD;
            }
        }
        cout<<ans%MOD<<endl;
    }

    return 0;
}

