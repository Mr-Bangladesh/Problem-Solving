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

ll A[200005],tree[800006];

void build(int N,int b,int e)
{
    if(b==e)
    {
        tree[N]=A[b];
        return;
    }
    int mid=(b+e)/2;

    build(N*2,b,mid);
    build(N*2+1,mid+1,e);

    tree[N]=tree[N*2]+tree[N*2+1];
}

void update(int N,int b,int e,int I,ll V)
{
    if(b>I || e<I) return;

    if(b==e && b==I)
    {
        tree[N]=V;
        return;
    }
    int  mid=(b+e)/2;

    update(N*2,b,mid,I,V);
    update(N*2+1,mid+1,e,I,V);

    tree[N]=tree[N*2]+tree[N*2+1];
}

ll query(int N,int b,int e,int I,int J)
{
    if(e<I || b>J) return 0;
    else if(b>=I && e<=J) return tree[N];

    int mid=(b+e)/2;

    ll P1=query(N*2,b,mid,I,J);
    ll P2=query(N*2+1,mid+1,e,I,J);

    return P1+P2;

}

int main()
{
    ///use always ll instead of int
    //sieve();
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    ll T,N,M,X,Y,W;
    int C=1;

    while(cin>>N)
    {
        if(N==0) break;
        if(C>1) cout<<endl;
        cout<<"Case "<<C++<<":"<<endl;
        string S;

        for(int i=1;i<=N;i++) cin>>A[i];

        build(1,1,N);

        while(cin>>S)
        {
            if(S=="END") break;

            cin>>X>>Y;

            if(S=="S")
            {
                update(1,1,N,X,Y);
            }
            else if(S=="M")
            {
                ll ans=query(1,1,N,X,Y);
                cout<<ans<<endl;
            }
        }

        //cout<<endl;

        memset(A,0,sizeof(A));
        memset(tree,0,sizeof(tree));
    }

    return 0;
}



