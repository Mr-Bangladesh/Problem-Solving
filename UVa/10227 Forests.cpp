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

map<int,int> Parent;

void init(int N)
{
    for(int i=1;i<=N;i++) Parent[i]=i;
}

int Find(int r)
{
    if(Parent[r]==r) return r;
    return Parent[r]=Find(Parent[r]);
}

int ans;

void Union(int X,int Y)
{
    int PX=Find(X); int PY=Find(Y);

    if(PX!=PY)
    {
        Parent[PX]=PY;
        ans--;
    }
}

int main()
{
    ///use always ll instead of int
    //sieve();

    ll T,N,M,X,Y,W;

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    cin>>T;

    while(T--)
    {
        cin>>N>>M;

        init(N);

        ans=N;

        //vector <ll> G[N+2];

        map<int, set<int> > G;

        cin.ignore();

        string S;

        while(getline(cin,S))
        {
            if(S.length()==0) break;

            int len=S.length();
            int num=0;
            for(int i=0;i<len;i++)
            {
                if(S[i]==' ')
                {
                    X=num;
                    num=0;
                    continue;
                }
                int r=S[i]-48;
                num=num*10 + r;
            }
            Y=num;

            G[X].insert(Y);
        }

        for(int i=1;i<=N;i++)
        {
            for(int j=i+1;j<=N;j++)
            {

                if(G[i].size()!=G[j].size()) continue;

                bool check=true;

                for(auto it=G[i].begin(),it1=G[j].begin();it!=G[i].end(),it1!=G[j].end();it++,it1++)
                {
                    int a=*it; int b=*it1;

                    if(a!=b)
                    {
                        check=false; break;
                    }
                }
                if(check) Union(i,j);
            }
        }

        cout<<ans<<endl;

        if(T) cout<<endl;

        ans=0;
        Parent.clear();
    }


    return 0;
}



