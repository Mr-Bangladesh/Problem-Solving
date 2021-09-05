#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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

    cin>>n>>k;
    r=0;
    ll a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        r=max(a[i],r);
    }

    ll l=1,mid=0; r+=k;

    ll ans=0;

    while(l<=r){
        mid=(l+r)/2;
        ll sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]<mid){
                sum+=(mid-a[i]);
            }
        }

        if(sum<=k){
            ans=max(ans,mid);
        }

        if(sum==k){
            break;
        }
        else if(sum>k) r=mid-1;
        else{
            l=mid+1;
        }
    }

    cout<<ans<<endl;

    return 0;
}



