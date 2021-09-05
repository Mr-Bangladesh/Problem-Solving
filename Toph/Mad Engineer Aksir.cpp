#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
ll tree[800005]={0};
void update(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return;

    if(b>=i && e<=j)
    {
        tree[node]++;
        return;
    }
    int mid=(b+e)/2;

    update(node*2,b,mid,i,j);
    update(node*2+1,mid+1,e,i,j);
}

int query(int node,int b,int e,int I,int carry)
{
    if(e<I || b>I) return 0;

    if(b==e)
    {
        return tree[node]+carry;
    }

    int mid=(b+e)/2;

    int R1=query(node*2,b,mid,I,carry+tree[node]);
    int R2=query(node*2+1,mid+1,e,I,carry+tree[node]);

    return R1+R2;
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n>>q;
    while(q--){
        cin>>x>>y;
        update(1,1,n,x,y);
    }
    for(int i=1;i<=n;i++){
        ll ans=query(1,1,n,i,0);
        if(ans%2){
            cout<<1;
        }
        else{
            cout<<0;
        }
        if(i!=n) cout<<" ";
    }
    cout<<endl;
    return 0;
}

