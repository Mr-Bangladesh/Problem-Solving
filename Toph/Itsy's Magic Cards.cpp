#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n>>m;
    char a,b;
    map<char,ll> cnt;
    map<char, set<char> > g;
    while(m--){
        cin>>a>>b;
        g[a].insert(b);
        g[b].insert(a);
        cnt[a]++; cnt[b]++;
    }

    set<char> ans;

    for(int i=0;i<n;i++){
        ans.insert(i+65);
    }

    priority_queue< pair<ll,char> > PQ;
    map<char,bool> mark;
    ll mx=-1;char ch;
    for(auto i:ans){
        if(cnt[i]>mx){
            mx=cnt[i];
            ch=i;
        }
    }

    PQ.push(mp(mx,ch));

    while(!PQ.empty()){
        auto u=PQ.top(); PQ.pop();
        if(u.first==0) break;
        else ans.erase(u.second);
        for(auto v:g[u.second]){
            g[v].erase(u.second);
            PQ.push(mp(g[v].size(),v));
        }
    }

    cout<<ans.size()<<endl;

    return 0;
}



