#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
//#define MAXX 200000
//vector<ll> Primes; ll isprime[MAXX+2],Ar[MAXX+100];
//void sieve(){
//    Primes.push_back(2);isprime[2]=1;
//    for(ll i=2;i<=MAXX;i+=2) Ar[i]=1;
//    for(ll i=3;i<=MAXX;i+=2){ if(Ar[i]==0) { Primes.push_back(i); isprime[i]=1; for(ll j=i*i;j<=MAXX;j+= i*2) Ar[j]=1;}}
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
ll pow(ll B,ll P) { ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;} ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

char S[1001][1001];

ll Fire[1001][1001],Mark[1001][1001];

void BFS(int S1,int S2,int N,int M)
{
    Mark[S1][S2]=1;
    queue< pair<int,int> > Q; Q.push(mp(S1,S2));

    Fire[S1][S2]=0;

    while(!Q.empty())
    {
        int U1=Q.front().first; int U2=Q.front().second; Q.pop();

        for(int i=0;i<4;i++)
        {
            int V1=U1+fx4[i]; int V2=U2+fy4[i];

            if(V1>=0 && V2>=0 && V1<N && V2<M && Mark[V1][V2]==0 && S[V1][V2]=='.')
            {
                Mark[V1][V2]=1;
                Q.push(mp(V1,V2));
                int X=Fire[U1][U2]+1;
                Fire[V1][V2]=min(Fire[V1][V2],X);
            }
        }
    }
}

int D[1001][1001];

int BFS2(int S1,int S2,int N,int M)
{
    Mark[S1][S2]=1;
    queue< pair<int,int> > Q; Q.push(mp(S1,S2));

    D[S1][S2]=0;

    while(!Q.empty())
    {
        int U1=Q.front().first; int U2=Q.front().second; Q.pop();

        for(int i=0;i<4;i++)
        {
            int V1=U1+fx4[i]; int V2=U2+fy4[i];

            if(V1>=0 && V2>=0 && V1<N && V2<M && Mark[V1][V2]==0 && S[V1][V2]=='.')
            {
                Mark[V1][V2]=1;
                Q.push(mp(V1,V2));
                int X=D[U1][U2]+1;

                if(Fire[V1][V2]<=X) return -1;

                D[V1][V2]=D[U1][U2]+1;

                if(V1==0 || V2==0 || V1==N-1 || V2==M-1) return D[V1][V2]+1;

            }
        }
    }
    return -1;
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
        cin>>N>>M;

        for(int i=0;i<N;i++) for(int j=0;j<M;j++) Fire[i][j]=INT_MAX;

        vector <pair<int,int> > V;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cin>>S[i][j];

                if(S[i][j]=='J'){ X=i;Y=j;}
                else if(S[i][j]=='F') V.pb(mp(i,j));
            }
        }
        for(int i=0;i<V.size();i++)
        {
            BFS(V[i].first,V[i].second,N,M);
            memset(Mark,0,sizeof(Mark));
        }
        //cout<<X<<" "<<Y<<endl;
        int ans=BFS2(X,Y,N,M);

        if(ans==-1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;

        memset(D,0,sizeof(D));
        memset(Fire,0,sizeof(Fire));
        memset(Mark,0,sizeof(Mark));
    }

    return 0;
}


