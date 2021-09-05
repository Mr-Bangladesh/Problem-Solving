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
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    while(t--){
        cin>>n;
        ll a,b,c;
        ll mxa=0,mxb=0,mxc=0;
        ll suma=0,sumb=0,sumc=0;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            mxa=max(mxa,a);
            mxb=max(mxb,b);
            mxc=max(mxc,c);
            suma+=a;
            sumb+=b;
            sumc+=c;
        }
        ll ans=min(suma*mxb*mxc,min(sumb*mxa*mxc,sumc*mxa*mxb));
        cout<<ans<<endl;
    }

    return 0;
}
