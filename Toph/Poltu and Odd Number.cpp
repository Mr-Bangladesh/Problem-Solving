#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
ll evenodd(ll A,ll B)
{
    ll numbers=B-A+1;
    ll even,odd;
    if((A%2==0 && B%2!=0) || (A%2!=0 && B%2==0))
    {
        odd=numbers/2;
        even=odd;
    }
    else if(A%2==0 && B%2==0)
    {
        odd=(B-A)/2;
        even=numbers-odd;
    }
    else if(A%2!=0 && B%2!=0)
    {
        even=(B-A)/2;
        odd=numbers-even;
    }
    return odd;
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    for(cs=1;cs<=t;cs++){
        cin>>x>>y;
        ll l=evenodd(1,y);
        ll r=evenodd(1,x-1);
        ll ans=(l*l)-r*r;
        printf("Case %lld: %lld\n",cs,ans);
    }

    return 0;
}

