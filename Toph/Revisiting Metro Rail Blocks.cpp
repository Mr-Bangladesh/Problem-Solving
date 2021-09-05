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
ll a[100000003],mark[100000003],cnt[100000003];
int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    ll g=1;
    cin>>x>>n;
    a[1]=1;
    for(int i=2;i<=n;i++){
        g=g*x;
        a[i]=g%(n+1);
        g=g%(n+1);
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;

//    for(int i=1;i<=n;i++){
//        x=a[i];
//        mark[x]=1;
//        cnt[i]=mark[x-1]+mark[x+1];
//    }
//
//    for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";

    return 0;
}

