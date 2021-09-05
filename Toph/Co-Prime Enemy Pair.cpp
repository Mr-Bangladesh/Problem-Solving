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
ll pp[1000006],res[1000006],mark[1000006];
ll lim=1000000;
vector<ll> v;
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);
    sieve();
    //cout<<A[27]<<endl;
    ll t,n,m,x,y,w,k,q,r,p,cs;
    for(auto x:Primes){
        y=x;
        ll i=1;
        while(y<=lim){
            v.pb(y);
            mark[y]=1;
            pp[y]=i;
            y=y*x;
            i++;
        }
    }
    sort(v.begin(),v.end());
    for(int i=2;i<=lim;i++){
        if(!mark[i]){
            res[i]=res[i-1];
            continue;
        }
        ll idx=upper_bound(v.begin(),v.end(),i)-v.begin(); idx--;
        res[i]=res[i-1]+idx-pp[v[idx]]+1;
    }
    cin>>t;
    for(cs=1;cs<=t;cs++){
        cin>>n;
        printf("Case %lld: %lld\n",cs,res[n]);
    }

    return 0;
}



