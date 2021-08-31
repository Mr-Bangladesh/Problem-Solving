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

ll modd=109546051211;

ll mulmod(ll a,ll b,ll M) {
    ll res = 0;
    while (a > 0) {
        if (a & 1) {
            res += b;
            if (res >= M) res -= M;
        }
        a >>= 1;
        b <<= 1;
        if (b >= M) b -= M;
    }
    return res;
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n;
    ll ans=1,f=1;
    for(ll i=1;i<=n;i++){
        f=((f%modd)*(i%modd))%modd;
        ans=mulmod(ans,f,modd);
        //cout<<i<<" "<<f<<" "<<ans<<endl;
    }
    cout<<ans<<endl;

    return 0;
}



