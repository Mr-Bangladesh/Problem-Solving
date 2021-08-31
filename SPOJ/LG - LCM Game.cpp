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

ll power(ll B,ll P){
    if(P==0) return 1;
    ll X=power(B,P/2);
    if(P%2==0) return X*X;
    else return B*X*X;
}

string multiply(string S,ll N){
    string S1=to_string(N);
    reverse(S.begin(),S.end()); reverse(S1.begin(),S1.end());
    ll l1=S.length(); ll l2=S1.length();
    for(ll i=l2;i<l1;i++){
        S1+='0';
    }
    vector<ll> V[1000];

        ll M=0;

        for(ll i=0;i<l2;i++){
            ll d=S1[i]-48;
            ll carry=0;

            for(ll j=0;j<i;j++) V[i].pb(0);

            for(ll j=0;j<l1;j++){
                ll d1=S[j]-48;
                ll m=d*d1+carry;
                V[i].pb(m%10);
                carry=m/10;
            }
            if(carry) V[i].pb(carry);
            M=max(M,V[i].size());
        }

        for(ll i=0;i<l2;i++){
            for(ll j=V[i].size();j<M;j++) V[i].pb(0);
        }

        vector<ll> ans;

        ll carry=0;
        for(ll i=0;i<M;i++){
                ll d=carry;
            for(ll j=0;j<l2;j++){
                d+=V[j][i];
            }
            //cout<<d<<endl;
            ans.pb(d%10);
            carry=d/10;
        }
        if(carry) ans.pb(carry);
        reverse(ans.begin(),ans.end());

        string ss;
        for(ll i=0;i<ans.size();i++) ss+=(ans[i]+48);
        return ss;
}


const ll maxx=100000;
ll status[(maxx>>5)+2];

bool check(ll N,ll pos)
{
    return (bool)(N & (1<<pos));
}
ll Set(ll N, ll pos)
{
    return N=(N|(1<<pos));
}
vector<ll>Primes;
void sieve()
{
    ll i,j,sqrtN;
    sqrtN=ll(sqrt(maxx))+1;
    Primes.pb(2);
    for(ll i=3;i<=maxx;i+=2)
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

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    sieve();

    while(scanf("%lld",&n)!=EOF){
        ll a[n+3];
        for(ll i=1;i<=n;i++) cin>>a[i];

        map<ll,ll> cnt;
        set<ll> pr;

        for(ll i=1;i<=n;i++){
            x=a[i];
            for(ll j=0;j<Primes.size() && Primes[j]*Primes[j]<=x;j++){
                if(x%Primes[j]) continue;
                ll c=0;
                pr.insert(Primes[j]);
                while(x%Primes[j]==0){
                    c++;
                    x/=Primes[j];
                }
                cnt[Primes[j]]=max(cnt[Primes[j]],c);
            }
            if(x!=1){
                cnt[x]=max(cnt[x],1);
                pr.insert(x);
            }
        }
        string ans="1";
        for(auto x:pr){
            ll value=power(x,cnt[x]);
            //cout<<x<<" "<<cnt[x]<<endl;
            ans=multiply(ans,value);
        }
        cout<<ans<<endl;
    }

    return 0;
}



