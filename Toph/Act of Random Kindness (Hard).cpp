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

ll par[1000005];
ll Find(ll r){
	if(par[r]==r) return r;
	else return par[r]=Find(par[r]);
}
ll cnt[1000005];
ll Union(ll x,ll y){
	ll px=Find(x); ll py=Find(y);
	if(px!=py){
		par[py]=px;
		cnt[px]+=cnt[py];
        return cnt[px];
	}
    else return cnt[px];
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    for(int i=1;i<=1000000;i++){
        par[i]=i;
        cnt[i]=1;
    }

    cin>>n;
    while(n--){
    	cin>>x>>y;
        ll xx=Union(x,y);
        ll ans=(xx*(xx-1))/2;
        cout<<ans<<endl;
    }

    return 0;
}