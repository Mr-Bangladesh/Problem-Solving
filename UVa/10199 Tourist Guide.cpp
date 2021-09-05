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

map<string,ll> node;
map<ll,string> node1;
map<ll, vector<ll> > G;
ll t=0,source;
map<ll,ll> mark,d,low,parent,isAP;
void AP(ll u){
    mark[u]=1;
    t++;
    d[u]=low[u]=t;
    ll c=0;
    for(int i=0;i<G[u].size();i++){
        ll v=G[u][i];
        if(v==parent[u]) continue;
        if(mark[v]) low[u]=min(low[u],d[v]);
        if(!mark[v]){
            parent[v]=u;
            AP(v);
            low[u]=min(low[u],low[v]);
            if(d[u]<=low[v] && u!=source) isAP[u]=1;
            c++;
        }
        if(c>1 && u==source) isAP[u]=1;
    }
    t++;
}
bool faizul(string a,string b){
    return a[0]<b[0];
}
vector<string> ans;

int main()
{
    ///use always ll instead of int
    //sieve();

    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll T,N,M,X,Y,W,K,Q,R,P;

    ll Case=0;

    while(cin>>N){
            //cout<<" N "<<N<<endl;
        if(!N) break;
        if(Case) cout<<endl;
        Case++;
        for(int i=1;i<=N;i++){
            string S;
            cin>>S;
            node[S]=i;
            node1[i]=S;
        }
        cin>>M;
        for(int i=1;i<=M;i++){
            string U,V;
            cin>>U>>V;
            X=node[U]; Y=node[V];
            G[X].pb(Y);
            G[Y].pb(X);
        }
        for(int i=1;i<=N;i++){
            if(!mark[i]){
                source=i;
                AP(i);
            }
        }

        for(int i=1;i<=N;i++){
            if(isAP[i]){
                ans.pb(node1[i]);
            }
        }
        sort(ans.begin(),ans.end());

        X=ans.size();

        //printf("City map #%lld: %lld camera(s) found\n",Case,X);
        cout<<"City map #"<<Case<<": "<<X<<" camera(s) found"<<endl;
        for(int i=0;i<X;i++) cout<<ans[i]<<endl;

        node.clear(); node1.clear(); G.clear(); d.clear(); low.clear();
        mark.clear(); parent.clear(); isAP.clear(); ans.clear();
    }

    return 0;
}
