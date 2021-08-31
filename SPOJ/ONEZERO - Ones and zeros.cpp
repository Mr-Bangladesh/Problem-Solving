#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 999999999999999999
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

ll F(string s,ll n){
    int len=s.length();
    ll r=0;
    for(int i=0;i<len;i++){
        r=(r*10 + s[i]-48)%n;
    }
    return r;
}

string bfs(ll n){
    map<ll,bool> mark;
    queue<string> q;
    string s="1";
    q.push(s);
    mark[1%n]=1;
    while(!q.empty()){
        string u=q.front(); q.pop();
        ll r=F(u,n);
        if(r==0) return u;
        //cout<<u<<endl;
        for(int i=0;i<=1;i++){
            string v=u;
            v+=(i+48);
            ll r1=F(v,n);
            if(!mark[r1]){
                mark[r1]=1;
                q.push(v);
            }
        }
    }

}

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    while(t--){
        cin>>n;
        string ans=bfs(n);
        cout<<ans<<endl;
    }

    return 0;
}



