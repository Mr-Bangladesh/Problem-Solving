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

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs,z,i,l;
    cs=1;
    while(cin>>z>>i>>m>>l){
        if(!z && !i && !m && !l) break;
        map<ll,ll> mark;
        ll cnt=1; mark[l]=1;
        while(1){
            l=(l*z+i)%m;
            cnt++;
            if(mark[l]){
                cnt-=mark[l];
                break;
            }
            mark[l]=cnt;
        }
        printf("Case %lld: %lld\n",cs,cnt);
        cs++;
    }

    return 0;
}
