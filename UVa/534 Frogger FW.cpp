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
double mysqrt(ll N){
    double high,low,mid; high=(double)N;low=0.0;for(ll i=1;i<=64;i++){ mid=(high+low)/2; if(mid*mid>N) high=mid; else low=mid;}
    return mid;}
//ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
//ll bigmod(ll B,ll P,ll M){ if(P==0) return 1; else if(P%2==0) { ll R=bigmod(B,P/2,M); return ((R%M)*(R%M))%M;}
//    else { ll R=bigmod(B,P-1,M); return ((R%M)*(B%M))%M;}
//}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll power(ll B,ll P){ if(P==0) return 1; ll X=power(B,P/2); if(P%2==0) return X*X; else return B*X*X;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

double max(double a,double b)
{
    if(a>b) return a;
    else return b;
}
double min(double a,double b)
{
    if(a<b) return a;
    else return b;
}

vector< pair<ll,ll> > V;

double Dist[300][300];

double FW(ll N)
{
    for(int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i==j) continue;

                Dist[i][j]=min(Dist[i][j],max(Dist[i][k],Dist[k][j]));
            }
        }
    }

    return Dist[0][1];
}

int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    T=0;

    while(cin>>N)
    {
        T++;
        if(N==0) break;

        for(int i=0;i<N;i++)
        {
            cin>>X>>Y;
            V.pb(mp(X,Y));
        }

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i==j) Dist[i][j]=0.00;
                else Dist[i][j]=(double) INF;
            }
        }

        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                X=V[i].first-V[j].first; Y=V[i].second-V[j].second;

                double D=mysqrt(X*X+Y*Y);

                Dist[i][j]=D;
                Dist[j][i]=D;

                //cout<<V[i].first<<" "<<V[i].second<<" "<<V[j].first<<" "<<V[j].second<<" "<<" "<<Dist<<endl;


            }
        }

        double ans=FW(N);

        printf("Scenario #%lld\nFrog Distance = %.3f\n\n",T,ans);

        V.clear(); memset(Dist,0,sizeof(Dist));
    }

    return 0;
}


