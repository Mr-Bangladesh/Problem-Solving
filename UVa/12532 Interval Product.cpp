#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000000+7
#define PI 2*acos(0.0)
//#define MAXX 10000000
//vector<ll> Primes; ll isprime[MAXX+2]; bool Ar[MAXX+100];
//void sieve(){
//    Ar[0]=1; Ar[1]=1;
//    for (ll i = 2; i <= MAXX; i++) {
//        if(Ar[i] == false) {
//            Primes.push_back(i);
//            isprime[i]=1;
//            for (ll j = 2 * i; j <= MAXX; j = j + i) {
//                Ar[j] = true;
//            }
//        }
//    }
//}
//double mysqrt(ll N){
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
ll A[100005],tree[400005];

void build(ll N,ll b,ll e)
{
    if(b==e)
    {
        if(A[b]>0) tree[N]=1;
        else if(A[b]<0) tree[N]=-1;
        else tree[N]=0;
        return;
    }
    ll mid=(b+e)/2;
    build(N*2,b,mid);
    build(N*2+1,mid+1,e);
    tree[N]=tree[N*2]*tree[N*2+1];
}

void update(ll N,ll b,ll e,ll I,ll V)
{
    if(e<I || b>I) return;

    if(b==e && b==I)
    {
        if(V>0) tree[N]=1;
        else if(V<0) tree[N]=-1;
        else tree[N]=0;
        return;
    }
    ll mid=(b+e)/2;

    update(N*2,b,mid,I,V);
    update(N*2+1,mid+1,e,I,V);

    tree[N]=tree[N*2]*tree[N*2+1];
}

ll query(ll N,ll b,ll e,ll I,ll J)
{
    if(I>e || J<b) return INF;
    else if(b>=I && e<=J) return tree[N];

    ll mid=(b+e)/2;

    ll P1=query(N*2,b,mid,I,J);
    ll P2=query(N*2+1,mid+1,e,I,J);

    if(P1==INF) return P2;
    else if(P2==INF) return P1;
    else return P1*P2;
}

int main()
{
    ///use always ll instead of int
    //sieve();

    ll T,N,M,X,Y,W;

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    while(cin>>N>>M)
    {
        for(ll i=1;i<=N;i++) cin>>A[i];

        build(1,1,N);

        char C; ll I,J;

        string S;

        for(ll i=1;i<=M;i++)
        {
            cin>>C>>I>>J;
            if(C=='C')
            {
                update(1,1,N,I,J);
            }
            else if(C=='P')
            {
                ll ans=query(1,1,N,I,J);
                if(ans==0) S+='0';
                else if(ans>0) S+='+';
                else S+='-';
            }
        }

        cout<<S<<endl;

        memset(A,0,sizeof(A));
        memset(tree,0,sizeof(tree));
    }

    return 0;
}



