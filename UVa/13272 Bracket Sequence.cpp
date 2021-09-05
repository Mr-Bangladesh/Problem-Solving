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

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    for(cs=1;cs<=t;cs++){
        string s;
        cin>>s;
        int len=s.length();
        stack<ll> idx;
        ll obs=-1;
        vector< pair<ll,ll> > pidx;

        for(int i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' || s[i]=='<') idx.push(i);
            else{
                if(idx.size()==0){
                    obs=i;
                }
                else{
                    int u=idx.top();
                    if(s[u]=='(' && s[i]==')'){
                        idx.pop();
                        if(obs<u || obs>i) pidx.pb(mp(u+1,i+1));
                    }
                    else if(s[u]=='{' && s[i]=='}'){
                        idx.pop();
                        if(obs<u || obs>i) pidx.pb(mp(u+1,i+1));
                    }
                    else if(s[u]=='[' && s[i]==']'){
                        idx.pop();
                        if(obs<u || obs>i) pidx.pb(mp(u+1,i+1));
                    }
                    else if(s[u]=='<' && s[i]=='>'){
                        idx.pop();
                        if(obs<u || obs>i) pidx.pb(mp(u+1,i+1));
                    }
                    else{
                        obs=i;
                    }
                }
            }
        }

        reverse(pidx.begin(),pidx.end());

        ll ans[len+5]={0};

        for(pair<ll,ll> u:pidx){
            ll x=u.first; ll y=u.second;
            ans[y]=0;
            ans[x]=y-x+1 + ans[y+1];
        }

        cout<<"Case "<<cs<<":"<<endl;
        for(int i=1;i<=len;i++){
            cout<<ans[i]<<endl;
        }
    }

    return 0;
}


