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

ll nCrModpDP(ll n, ll r, ll p)
{
    ll C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
ll nCrModpLucas(ll n, ll r, ll p)
{
   if (r==0)
      return 1;
   ll ni = n%p, ri = r%p;
   return (nCrModpLucas(n/p, r/p, p) * nCrModpDP(ni, ri, p)) % p;
}
ll primepower(ll n,ll p){
    ll cnt=0;
    while(n!=0){
        cnt+=n/p;
        n=n/p;
    }
    return cnt;
}
ll log3(ll n){
    ll cnt=0;
    while(n!=0){
        cnt++;
        n/=3;
    }
    return cnt-1;
}
ll g[30]={0};
void init(){
    for(int i=1;i<=27;i++){
        if(__gcd(i,3)==1) g[i]=i;
        else g[i]=1;
    }
}
ll f27;
ll f(ll n){
    if(n==0) return 1;
    ll r=pow(f27,n/27);
    r*=(f(n/3))%27;
    for(int i=1;i<=n%27;i++){
        r*=g[i];
        r%=27;
    }
    return r;
}
ll F(ll n){
    ll len=log3(n);
    ll sum=0;
    for(int e=0;e<=len;e++){
        ll x=pow(3,e);
        sum=(sum+(f(n/x)%27))%27;
    }
}
ll ModInv(ll a, ll m)
{
	ll m0 = m, t, q;
	ll x0 = 0, x1 = 1;
	if (m == 1)
   	return 0;
	while (a > 1)
	{
    	q = a / m;
    	t = m;
    	m = a % m, a = t;
    	t = x0;
    	x0 = x1 - q * x0;
    	x1 = t;
	}
	if (x1 < 0)
   	x1 += m0;
	return x1;
}

ll FindMinX(ll num[],ll rem[],ll n){
    ll prod=1;
    for(int i=1;i<=n;i++) prod*=num[i];
    ll res=0;
    for(int i=1;i<=n;i++){
        ll pp=prod/num[i];
        res+=(rem[i]*ModInv(pp,num[i])*pp);
    }
    return res%prod;
}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    while(t--){
        cin>>n>>r;
        ll a=nCrModpLucas(n,r,11);
        ll b=nCrModpLucas(n,r,13);
        ll c=nCrModpLucas(n,r,37);
        init();
        f27=1;
        for(int i=1;i<27;i++){
            f27*=g[i];
            f27%=27;
        }
        ll e=primepower(n,3)-primepower(r,3)-primepower(n-r,3);
        x=F(r); y=F(n-r);
        ll d=pow(3,e);
        d*=(F(n)*ModInv(x,27)*ModInv(y,27))%27;
        ll rem[5]={0},num[5]={0};
        num[1]=11;num[2]=13;num[3]=27;num[4]=37;
        rem[1]=a; rem[2]=b;rem[3]=d; rem[4]=c;
        ll ans=FindMinX(num,rem,4);
        cout<<ans<<endl;
    }

    return 0;
}
