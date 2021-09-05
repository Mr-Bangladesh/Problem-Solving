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
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    while(t--){
        cin>>n;
        ll a[n+2];
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n==1){
            cout<<0<<endl; continue;
        }
        ll ans=0;
        if(a[1]==0){
            if(a[2]%2){
                a[1]=1;
            }
            else if(a[2]>0 && a[2]%2==0){
                a[1]=2;
            }
            else{
                a[1]=1;
            }
        }
        for(int i=2;i<=n;i++){
            if(a[i]==0){
                if(a[i-1]%2){
                    a[i]=1;
                }
                else{
                    a[i]=2;
                }
            }
            if(a[i]%2!=a[i-1]%2) ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}

