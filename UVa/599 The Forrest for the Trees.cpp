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

map<char,char> Parent;

void INIT()
{
    for(char i='A';i<='Z';i++) Parent[i]=i;
}

char Find(char r)
{
    if(Parent[r]==r) return r;
    return Parent[r]=Find(Parent[r]);
}

int comp;

void Union(char X,char Y)
{
    char PX=Find(X); char PY=Find(Y);

    if(PX!=PY)
    {
        comp--;
        Parent[PX]=PY;
    }
}

int main()
{
    ///use always ll instead of int
    //sieve();

    ll T,N,M,X,Y,W;

    //freopen("1.txt","r",stdin);

    cin>>T;

    while(T--)
    {
        string S;

        vector<char> G[100];

        vector < pair<char,char> > E;

        while(cin>>S)
        {
            if(S[0]=='*') break;
            char U=S[1];
            char V=S[3];
            G[U].pb(V);
            G[V].pb(U);
            E.pb(mp(U,V));
        }

        string S1;

        cin>>S1;

        int len=S1.length();

        INIT();

        X=0,Y=0;

        comp=0;

        for(int i=0;i<len;i++)
        {
            if(S1[i]!=',') comp++;
        }

        for(int i=0;i<E.size();i++)
        {
            Union(E[i].first,E[i].second);
        }

        for(int i=0;i<len;i++)
        {
            if(S1[i]==',') continue;

            if(G[S1[i]].size()==0) X++;
        }

        printf("There are %lld tree(s) and %lld acorn(s).\n",comp-X,X);

        Parent.clear();
        comp=0;
    }


    return 0;
}



