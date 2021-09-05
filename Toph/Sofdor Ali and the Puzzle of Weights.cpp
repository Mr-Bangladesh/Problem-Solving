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

    ll sum=0;
    vector<ll> v;
    for(int i=1;i<=40;i++){
        x=sum+1;
        y=sum+x;
        sum+=y;
        //cout<<i<<" "<<sum<<endl;
        v.pb(sum);
    }

    scanf("%lld",&t);

    for(cs=1;cs<=t;cs++){
        scanf("%lld",&n);
        ll idx=lower_bound(v.begin(),v.end(),n)-v.begin();
        printf("Case %lld: %lld\n",cs,idx+1);
    }

    return 0;
}


