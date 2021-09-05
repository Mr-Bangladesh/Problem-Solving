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
map<ll, vector<ll> >g;
ll A[2000005];
ll lim=2000000;
void phi()
{
	for(ll i=2;i<=lim;i++) A[i]=i;
	for(ll x:Primes){
    	for(ll i=x;i<=lim;i+=x){
        	A[i]=(A[i]*(x-1))/x;
    	}
	}
	for(int i=2;i<=lim;i++){
        g[A[i]].pb(i);
	}
}
ll mark[2000005],level[2000005];
void bfs(){
    mark[1]=1; level[1]=0;
    queue<ll> q; q.push(1);
    while(!q.empty()){
        ll u=q.front(); q.pop();
        for(ll v:g[u]){
            if(!mark[v]){
                mark[v]=1;
                q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    sieve();
    phi();
    bfs();

    for(int i=2;i<=lim;i++){
        level[i]+=level[i-1];
    }
    cin>>t;
    while(t--){
        cin>>x>>y;
        cout<<level[y]-level[x-1]<<endl;
    }

    return 0;
}
