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
int fx4[]={-1,-1,-1,0,0,1,1,1};
int fy4[]={1,0,-1,1,-1,1,0,-1};

char G[105][105];int Mark[105][105];
int N,M;
vector< pair<int,int> > V;
int Count=0;

void DFS(int u1,int u2)
{
    //cout<<u1<<" "<<u2<<endl;
    Count++;
    Mark[u1][u2]=1;
    for(int i=0;i<8;i++)
    {
        int v1=u1+fx4[i];
        int v2=u2+fy4[i];

        if(v1>0 && v2>0 && v1<=N && v2<=M && G[v1][v2]=='W' && Mark[v1][v2]==0)
        {
            Mark[v1][v2]=1;
            DFS(v1,v2);
        }
    }
}

int main()
{
    ///use always ll instead of int
    //sieve();

    ll T,X,Y,W;

    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    cin>>T;

    string a;

    getline(cin,a);

    cin.ignore();

    while(T--)
    {
        memset(Mark,0,sizeof(Mark));
        V.clear(); Count=0;

        for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) G[i][j]='\0';

        string S;

        N=1;

        while(getline(cin,S))
        {
            if(S[0]=='\0') break;
            else if(S[0]=='L' || S[0]=='W')
            {
                int len=S.length();

                for(int i=0;i<len;i++) G[N][i+1]=S[i];

                //cout<<T<<" "<<N<<" "<<S<<endl;

                M=len;
                N++;
            }
            else
            {
                V.pb(mp(S[0]-48,S[2]-48));
            }
        }

        N--;

        //for(int i=0;i<V.size();i++) cout<<V[i].first<<" "<<V[i].second<<" "<<T<<endl;
//        for(int i=1;i<=N;i++)
//        {
//            for(int j=1;j<=M;j++) cout<<G[i][j]<<" "; cout<<endl;
//        }

        for(int i=0;i<V.size();i++)
        {
            DFS(V[i].first,V[i].second);
            cout<<Count<<endl;
            memset(Mark,0,sizeof(Mark));
            Count=0;
        }

        if(T) cout<<endl;

    }

    return 0;
}



