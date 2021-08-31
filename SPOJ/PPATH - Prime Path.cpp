#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
const ll maxx=10005;
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

class graph{
public:
    map<ll,vector<ll> > g;
    bool check(ll a,ll b);
    void init();
    ll bfs(ll s,ll t);
};
bool graph::check(ll a,ll b){
        ll cnt=0;
        while(a!=0){
            ll r1=a%10;
            ll r2=b%10;
            a/=10;
            b/=10;
            if(r1!=r2){
                cnt++;
            }
        }
        if(cnt==1) return 1;
        else return 0;
    }

void graph::init(){
        ll i=upper_bound(Primes.begin(),Primes.end(),1000)-Primes.begin();
        ll j=lower_bound(Primes.begin(),Primes.end(),10000)-Primes.begin(); j--;

        for(int k=i;k<=j;k++){
            for(int l=k+1;l<=j;l++){
                if(check(Primes[k],Primes[l])){
                    g[Primes[k]].pb(Primes[l]);
                    g[Primes[l]].pb(Primes[k]);
                }
            }
        }
    }

ll graph::bfs(ll s,ll t){
        queue<ll> q; q.push(s);
        map<ll,bool> mark;
        map<ll,ll> level;
        mark[s]=1;
        level[s]=0;
        graph x;

        while(!q.empty()){
            ll u=q.front(); q.pop();
            for(ll v:g[u]){
                if(!mark[v]){
                    mark[v]=1;
                    level[v]=level[u]+1;
                    q.push(v);
                    if(mark[t]) return level[t];
                    //cout<<u<<" "<<v<<endl;
                }
            }
        }
        return level[t];
    }

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,y,w,k,q,r,p,cs;

    sieve();
    graph x;
    x.init();

    cin>>t;

    while(t--){
        cin>>n>>m;
        ll ans=x.bfs(n,m);
        cout<<ans<<endl;
    }

    return 0;
}



