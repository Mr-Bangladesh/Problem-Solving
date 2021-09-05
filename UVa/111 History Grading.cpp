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

vector<pair<ll,ll> > V,A;
vector<ll> Arr;
map<ll,ll> mm;
ll L[100];

void input(string S){
    int len=S.length();
    if(len==0) return;
    ll N=0,X;
    for(int i=0;i<len;i++){
        N=N*10+(S[i]-48);
    }
    A.pb(mp(0,0));
    for(int i=1;i<=N;i++){
        cin>>X;
        A.pb(mp(X,i));
    }
    sort(A.begin(),A.end());
    for(int i=1;i<=N;i++){
        mm[A[i].second]=i;
    }

    //for(int i=1;i<=N;i++) cout<<A[i].second<<" "<<mm[A[i].second]<<endl;
}

int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    string S;

    while(getline(cin,S)){
        int len=S.length();
        if(!len) continue;
        if(len<=2){
            V.clear();
            A.clear();
            mm.clear();
            input(S);
        }
        else{
            S+=" ";
            X=0;
            V.pb(mp(0,0));
            ll I=1;
            for(int i=0;i<=len;i++){
                if(S[i]==32){
                    V.pb(mp(X,I));
                    X=0;I++;
                    continue;
                }
                X=X*10+(S[i]-48);
            }

            sort(V.begin(),V.end());

            int x=1;
            N=V.size()-1;
            Arr.pb(0);
            for(int i=1;i<=N;i++){
                Arr.pb(mm[V[i].second]);
            }

            //for(int i=1;i<=N;i++) cout<<V[i].second<<" "<<mm[V[i].second]<<endl;

            for(int i=1;i<=N;i++)
            {
                for(int j=i+1;j<=N;j++)
                {
                    if(Arr[j]>Arr[i])
                    {
                        if(L[j]<L[i]+1)
                        {
                            L[j]=L[i]+1;
                            x=max(x,L[j]+1);
                        }
                    }
                }
            }

            //for(int i=1;i<=N;i++) cout<<Arr[i]<<" "; cout<<endl;

            cout<<x<<endl;
            memset(L,0,sizeof(L));

            V.clear(); Arr.clear();
        }
    }

    return 0;
}
