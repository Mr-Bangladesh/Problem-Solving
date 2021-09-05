/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }
} * root;

void add(vector<ll> v,int n){
    node* cur=root;
    int cnt=0;
    for(int i=0;i<n;i++){
        int id=v[i];
        if(cur->next[id]==NULL){
            cur->next[id]=new node();
            cnt++;
        }
        cur=cur->next[id];
    }
    cur->endmark=true;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}
ll a[500005];
vector<ll> g[500005];
ll tt=0;
ll dt[500005],ft[500005];
void dfs(ll u,ll par){
    tt++;
    dt[u]=tt;
    for(ll v:g[u]){
        if(v==par) continue;
        dfs(v,u);
    }
    tt++;
    ft[u]=tt;
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vector<ll> v;
        x=a[i];
        while(x!=0){
            v.pb(x%10);
            x/=10;
        }
        reverse(v.begin(),v.end());
        add(v,v.size());
    }

    for(int i=1;i<n;i++){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,-1);
    root=new node();



    del(root);

    return 0;
}
