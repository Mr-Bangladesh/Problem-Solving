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
const ll maxx=10000000;
int status[(maxx>>5)+2];

bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N, int pos)
{
    return N=(N|(1<<pos));
}
vector<ll>Primes;
void sieve()
{
    ll i,j,sqrtN;
    sqrtN=ll(sqrt(maxx))+1;
    Primes.pb(2);
    for(int i=3;i<=maxx;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            Primes.pb(i);

            if(i<=sqrtN)
            for(j=i*i;j<=maxx;j+=(i<<1))
            {
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
}
ll A[200005];
ll lim=200000;
void phi()
{
	A[0]=1;
	for(ll i=1;i<=lim;i++) A[i]=i;
	for(ll x:Primes){
    	for(ll i=x;i<=lim;i+=x){
        	A[i]=(A[i]*(x-1))/x;
    	}
	}
	for(ll i=1;i<=lim;i++){
    	A[i]+=A[i-1];
	}
}


int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    sieve();
    phi();
    while(cin>>n){
        if(!n) break;
        if(n==1){
            cout<<0<<"/"<<1<<endl; continue;
        }
        if(n==2){
            cout<<1<<"/"<<1<<endl; continue;
        }
        ll idx=lower_bound(A,A+lim+1,n)-A;
        x=n-A[idx-1];
        ll ans;
        //cout<<idx<<" "<<x<<endl;
        for(ll i=1;x>0;i++){
            if(__gcd(idx,i)==1){
                x--;
            }
            if(x==0){
                ans=i;break;
            }
        }
        cout<<ans<<"/"<<idx<<endl;
    }

    return 0;
}
