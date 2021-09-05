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


map<char, vector <char> > G;
map<char,int> Mark;

map<char,int> level;
int BFS(char S)
{
    Mark[S]=1;
    level[S]=0; int Count=3;

    queue<char> Q; Q.push(S);

    while(!Q.empty())
    {
        char U=Q.front(); Q.pop();
        if(U!=S) Count++;

        for(int i=0;i<G[U].size();i++)
        {
            char V=G[U][i];

            if(Mark[V]==0)
            {
                Mark[V]=1;
                level[V]=level[U]+1;
                //cout<<"visited "<<V<<" "<<level[V]<<endl;
                Q.push(V);
            }
        }
    }

    return Count;
}


int main()
{
    ///use always ll instead of int
    //sieve();

    freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    ll T,N,M,X,Y,W;

    string S;

    //cin.ignore();

    while(cin>>N>>M)
    {

        string source;

        cin>>source;

        string E;

        set<char> node;

        for(int i=1;i<=M;i++)
        {
            cin>>E; //cout<<E<<endl;
            bool check=true;
            for(int j=0;j<3;j++)
            {
                if(source[j]==E[0])
                {
                    G['1'].pb(E[1]); //cout<<source[j]<<" "<<E[0]<<endl;
                    G[E[1]].pb('1');
                    node.insert(E[1]);
                    check=false; break;
                }
                else if(source[j]==E[1])
                {
                    G['1'].pb(E[0]);
                    G[E[0]].pb('1');
                    node.insert(E[0]);
                    check=false; break;
                }
            }

            if(!check) continue;

            G[E[0]].pb(E[1]);
            G[E[1]].pb(E[0]);
            node.insert(E[0]);
            node.insert(E[1]); //cout<<E[0]<<" "<<E[1]<<endl;
        }

        for(auto it=node.begin();it!=node.end();it++)
        {
            level[*it]=-1;
        }

        int ans=BFS('1');

        set<int> a;

        for(auto it=node.begin();it!=node.end();it++)
        {
            //cout<<*it<<" "<<level[*it]<<endl;
            a.insert(level[*it]);
        }

        int ans1=a.size();

        //for(int i=0;i<G['1'].size();i++) cout<<G['1'][i]<<" "; cout<<endl;


        if(ans==N) cout<<"WAKE UP IN, "<<(ans1)<<", YEARS"<<endl;
        else cout<<"THIS BRAIN NEVER WAKES UP"<<endl;

        cin.ignore();
    }

    return 0;
}



