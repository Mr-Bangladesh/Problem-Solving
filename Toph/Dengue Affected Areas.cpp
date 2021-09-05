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
int a[100005];
vector<int> tree[400008];
void build(int n,int b,int e){
    if(b==e){
        tree[n].pb(a[b]);
        return;
    }
    int mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    merge(tree[n*2].begin(),tree[n*2].end(),tree[n*2+1].begin(),tree[n*2+1].end(),back_inserter(tree[n]));
}
int query1(int n,int b,int e,int i,int j,int p,int q){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j){
        int x=lower_bound(tree[n].begin(),tree[n].end(),p)-tree[n].begin();
        int y=upper_bound(tree[n].begin(),tree[n].end(),q)-tree[n].begin();
        return y-x;
    }
    int mid=(b+e)/2;
    int x=query1(n*2,b,mid,i,j,p,q);
    int y=query1(n*2+1,mid+1,e,i,j,p,q);
    return x+y;
}
ll query2(int n,int b,int e,int i,int j,int p,int q){
    if(i>e || j<b) return INT_MAX;
    if(b>=i && e<=j){
        int x=lower_bound(tree[n].begin(),tree[n].end(),p)-tree[n].begin();
        int y=upper_bound(tree[n].begin(),tree[n].end(),q)-tree[n].begin();
        if(y-x>=1){
            return tree[n][x];
        }
        else return INT_MAX;
    }
    int mid=(b+e)/2;
    int x=query2(n*2,b,mid,i,j,p,q);
    int y=query2(n*2+1,mid+1,e,i,j,p,q);
    return min(x,y);
}
ll query3(int n,int b,int e,int i,int j,int p,int q){
    if(i>e || j<b) return -1;
    if(b>=i && e<=j){
        int x=lower_bound(tree[n].begin(),tree[n].end(),p)-tree[n].begin();
        int y=upper_bound(tree[n].begin(),tree[n].end(),q)-tree[n].begin();
        if(y-x>=1){
            return tree[n][y-1];
        }
        else return -1;
    }
    int mid=(b+e)/2;
    int x=query3(n*2,b,mid,i,j,p,q);
    int y=query3(n*2+1,mid+1,e,i,j,p,q);
    return max(x,y);
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    int t,n,m,x,y,w,k,q,r,p,cs,l,z;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        cin>>l>>r>>p>>q;
        x=query1(1,1,n,l,r,p,q);
        y=query2(1,1,n,l,r,p,q);
        if(y==INT_MAX) y=-1;
        z=query3(1,1,n,l,r,p,q);
        cout<<x<<" "<<y<<" "<<z<<endl;
    }

    return 0;
}


