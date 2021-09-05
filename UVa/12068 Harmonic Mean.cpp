#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
//const ll maxx=10000000;
//int status[(maxx>>5)+2];
//
//bool check(int N,int pos)
//{
//    return (bool)(N & (1<<pos));
//}
//int Set(int N, int pos)
//{
//    return N=(N|(1<<pos));
//}
//vector<ll>Primes;
//void sieve()
//{
//    ll i,j,sqrtN;
//    sqrtN=ll(sqrt(maxx))+1;
//    Primes.pb(2);
//    for(int i=3;i<=maxx;i+=2)
//    {
//        if(check(status[i>>5],i&31)==0)
//        {
//            Primes.pb(i);
//
//            if(i<=sqrtN)
//            for(j=i*i;j<=maxx;j+=(i<<1))
//            {
//                status[j>>5]=Set(status[j>>5],j & 31);
//            }
//        }
//    }
//}
////double mysqrt(ll N){
//    double high,low,mid; high=(double)N;low=0.0;for(ll i=1;i<=64;i++){ mid=(high+low)/2; if(mid*mid>N) high=mid; else low=mid;}
//    return mid;}
//ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
//ll bigmod(ll B,ll P,ll M){ if(P==0) return 1; else if(P%2==0) { ll R=bigmod(B,P/2,M); return ((R%M)*(R%M))%M;}
//    else { ll R=bigmod(B,P-1,M); return ((R%M)*(B%M))%M;}
//}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll power(ll B,ll P){ if(P==0) return 1; ll X=power(B,P/2); if(P%2==0) return X*X; else return B*X*X;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

ll F(ll a,ll b){
    ll g=__gcd(a,b);
    return (a*b)/g;
}

int main()
{
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    cin>>T;
    for(ll C=1;C<=T;C++){
        cin>>N;
        ll A[N+5];
        ll lcm=1;
        for(int i=1;i<=N;i++){
            cin>>A[i];
            lcm=F(lcm,A[i]);
        }
        ll s=0;
        for(int i=1;i<=N;i++) s+=(lcm/A[i]);
        ll g=__gcd(N*lcm,s);
        X=(N*lcm)/g;
        Y=s/g;
        printf("Case %lld: ",C);
        cout<<X<<"/"<<Y<<endl;
    }

    return 0;
}

