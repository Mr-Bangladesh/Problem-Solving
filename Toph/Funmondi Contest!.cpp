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
ll sum=0;
ll cnt[200005];
ll a[200005];
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]) sum++;
    }

    while(q--){
        cin>>x>>y;
        if(x==1){
            a[y]--;
            if(a[y]==0) sum--;
        }
        else{
            a[y]++;
            if(a[y]==1) sum++;
        }
        cout<<sum<<endl;
    }

    return 0;
}

