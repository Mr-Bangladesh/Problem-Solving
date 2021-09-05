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

    ll a[100],b[100],c[100];
    x=1;
    a[0]=b[0]=c[0]=1;
    for(ll i=1;i<=62;i++){
        x=x*2;
        a[i]=x;
    }
    x=1;
    for(int i=1;i<=39;i++){
        x=x*3; //cout<<x<<endl;
        b[i]=x;
    }
    x=1;
    for(int i=1;i<=27;i++){
        x=x*5; //cout<<i<<" "<<x<<endl;
        c[i]=x;
    }
    ll cnt=0;

    vector<ll> v;
    for(int i=0;i<=62;i++){
        for(int j=0;j<=39;j++){
            for(int k=0;k<=27;k++){
                x=a[i]*b[j]*c[k];
               if(x>0) v.pb(x);
            }
        }
    }
    sort(v.begin(),v.end());
    printf("The 1500'th ugly number is %lld.\n",v[1499]);
    return 0;
}

