/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
int a[502][502],trmin[2005][503],N,trmax[2005][502];
void build(int n,int b,int e){
    if(b==e){
        for(int i=1;i<=N;i++){
            trmin[n][i]=trmax[n][i]=a[b][i];
        }
        return;
    }
    int mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    for(int i=1;i<=N;i++){
        trmin[n][i]=min(trmin[n*2][i],trmin[n*2+1][i]);
        trmax[n][i]=max(trmax[n*2][i],trmax[n*2+1][i]);
    }
}
void update(int n,int b,int e,int i,int j,int v){
    if(e<i || b>i) return;
    if(b==e){
        trmin[n][j]=trmax[n][j]=v;
        return;
    }
    int mid=(b+e)/2;
    update(n*2,b,mid,i,j,v);
    update(n*2+1,mid+1,e,i,j,v);
    for(int i=1;i<=N;i++){
        trmin[n][i]=min(trmin[n*2][i],trmin[n*2+1][i]);
        trmax[n][i]=max(trmax[n*2][i],trmax[n*2+1][i]);
    }
}
pair<int,int> query(int n,int b,int e,int i,int y1,int j,int y2){
    if(i>e || j<b) return {INT_MAX,INT_MIN};
    if(b>=i && e<=j){
        int mn=INT_MAX,mx=INT_MIN;
        for(int k=y1;k<=y2;k++){
            mn=min(mn,trmin[n][k]);
            mx=max(mx,trmax[n][k]);
        }
        //cout<<"query "<<i<<" "<<y1<<" "<<j<<" "<<y2<<" "<<mn<<" "<<mx<<endl;
        return {mn,mx};
    }
    pair<int,int> x,y;
    int mid=(b+e)/2;
    x=query(n*2,b,mid,i,y1,j,y2);
    y=query(n*2+1,mid+1,e,i,y1,j,y2);
    return {min(x.first,y.first),max(x.second,y.second)};
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    N=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    build(1,1,n);

    int q;
    scanf("%d",&q);
    string s; int a,b,c,d;
    while(q--){
        cin>>s;
        if(s[0]=='q'){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            pair<int,int> ans=query(1,1,n,a,b,c,d);
            printf("%d %d\n",ans.second,ans.first);
        }
        else{
            scanf("%d %d %d",&a,&b,&c);
            update(1,1,n,a,b,c);
        }
    }

    return 0;
}

