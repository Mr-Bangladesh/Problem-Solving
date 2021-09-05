#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
//#define MAXX 10000000
//vector <ll> Primes;
//ll status[MAXX/32];
//bool check(ll N,ll pos){
//    return (bool) (N & (1<<pos));
//}
//ll SET(ll N,ll pos){
//    return (N  (1<<pos));
//}
//void Bitwise_seive(){
//    Primes.push_back(2);
//    for(ll i=3;i<=MAXX;i+=2){
//        if(check(status[i/32],i%32)==0){
//            Primes.push_back(i);
//            for(ll j=i*i;j<=MAXX;j+= i*2){
//                status[j/32]=SET(status[j/32],j%32);
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

string F(string S,ll N){
    string S1=to_string(N);
    reverse(S.begin(),S.end()); reverse(S1.begin(),S1.end());
    int l1=S.length(); int l2=S1.length();
    for(int i=l2;i<l1;i++){
        S1+='0';
    }
    vector<ll> V[1000];

        ll M=0;

        for(int i=0;i<l2;i++){
            ll d=S1[i]-48;
            ll carry=0;

            for(int j=0;j<i;j++) V[i].pb(0);

            for(int j=0;j<l1;j++){
                ll d1=S[j]-48;
                ll m=d*d1+carry;
                V[i].pb(m%10);
                carry=m/10;
            }
            if(carry) V[i].pb(carry);
            M=max(M,V[i].size());
        }

        for(int i=0;i<l2;i++){
            for(int j=V[i].size();j<M;j++) V[i].pb(0);
        }

        vector<ll> ans;

        ll carry=0;
        for(int i=0;i<M;i++){
                ll d=carry;
            for(int j=0;j<l2;j++){
                d+=V[j][i];
            }
            //cout<<d<<endl;
            ans.pb(d%10);
            carry=d/10;
        }
        if(carry) ans.pb(carry);
        reverse(ans.begin(),ans.end());

        string ss;
        for(int i=0;i<ans.size();i++) ss+=(ans[i]+48);
        return ss;
}
string res[1005];
int main()
{
    //Bitwise_seive();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    res[0]="1"; res[1]="1";

    for(int i=2;i<=1005;i++){
        res[i]=F(res[i-1],i);
    }

    while(cin>>N){
        cout<<N<<"!"<<endl;
        cout<<res[N]<<endl;
    }

    return 0;
}


