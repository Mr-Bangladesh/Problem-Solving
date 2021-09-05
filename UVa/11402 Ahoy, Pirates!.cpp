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
string s;
int zero[4000005],one[1000005],invert[1000005],tr[1000005];
void build(int n,int b,int e){
    if(b==e){
        tr[n]=s[b-1]-48;
        zero[n]=one[n]=invert[n]=0;
        return;
    }
    int mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    tr[n]=tr[n*2]+tr[n*2+1];
}
void propagate_invert(int n,int b,int e){
    int mid=(b+e)/2;
    invert[n*2]=invert[n*2+1]=invert[n];
    invert[n]=0;
    tr[n*2]=mid-b+1-tr[n*2];
    tr[n*2+1]=e-mid-tr[n*2+1];
    tr[n]=tr[n*2]+tr[n*2+1];
}
void propagate_one(int n,int b,int e){
    int mid=(b+e)/2;
    one[n*2]=one[n*2+1]=one[n];
    one[n]=0;
    invert[n]=zero[n]=0;
    tr[n*2]=mid-b+1;
    tr[n*2+1]=e-mid;
    tr[n]=tr[n*2]+tr[n*2+1];
}
void propagate_zero(int n,int b,int e){
    int mid=(b+e)/2;
    zero[n*2]=zero[n*2+1]=zero[n];
    zero[n]=0;
    invert[n]=one[n]=0;
    tr[n*2]=tr[n*2+1]=0;
    tr[n]=tr[n*2]+tr[n*2+1];
}
void update(int n,int b,int e,int i,int j,int typ){
    if(b>j || e<i) return;
    if(invert[n]){
        propagate_invert(n,b,e);
    }
    if(one[n]){
        propagate_one(n,b,e);
    }
    if(zero[n]){
        propagate_zero(n,b,e);
    }
    if(b>=i && e<=j){
        if(typ==1){
            zero[n]=1;
            tr[n]=0;
            //one[n]=zero[n]=0;
        }
        else if(typ==2){
            one[n]=1;
            tr[n]=e-b+1;
            //zero[n]=invert[n]=0;
        }
        else{
            invert[n]=1;
            tr[n]=e-b+1-tr[n];
            //one[n]=zero[n]=0;
        }
        cout<<"update "<<i<<" "<<j<<" type "<<typ<<" "<<b<<" "<<e<<" "<<tr[n]<<" "<<zero[n]<<" "<<one[n]<<" "<<invert[n]<<endl;
        return;
    }
    int mid=(b+e)/2;
    update(n*2,b,mid,i,j,typ);
    update(n*2+1,mid+1,e,i,j,typ);
    tr[n]=tr[n*2]+tr[n*2+1];
    cout<<b<<" "<<e<<" "<<n<<" "<<tr[n]<<endl;
}
int query(int n,int b,int e,int i,int j){
    if(b>j || e<i) return 0;
    if(invert[n]){
        propagate_invert(n,b,e);
    }
    if(one[n]){
        propagate_one(n,b,e);
    }
    if(zero[n]){
        propagate_zero(n,b,e);
    }
    if(b>=i && e<=j){
        //cout<<"query "<<i<<" "<<j<<" "<<b<<" "<<e<<" "<<tr[n]<<endl;
        return tr[n];
    }
    int mid=(b+e)/2;
    int x=query(n*2,b,mid,i,j);
    int y=query(n*2+1,mid+1,e,i,j);
    //cout<<"query "<<b<<" "<<mid<<" "<<x<<"   "<<mid+1<<" "<<e<<" "<<y<<endl;
    //cout<<"query "<<i<<" "<<j<<" "<<b<<" "<<e<<" "<<x+y<<endl;
    return x+y;
}

int main()
{
    int t;
    freopen("1.txt","r",stdin);
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int m;
        scanf("%d",&m);
        int t;string a;
        for(int i=1;i<=m;i++){
            scanf("%d",&t); cin>>a;
            string b;
            for(int j=1;j<=t;j++){
                b+=a;
            }
            s+=b;
        }
        //cout<<s<<endl;
        int n=s.length();
        build(1,1,n);
        int q;
        scanf("%d",&q);
        while(q--){
            string a; int x,y;
            cin>>a; scanf("%d %d",&x,&y);
            x++; y++;
            if(a[0]=='F'){
                update(1,1,n,x,y,2);
            }
            else if(a[0]=='E'){
                update(1,1,n,x,y,1);
            }
            else if(a[0]=='I'){
                update(1,1,n,x,y,3);
            }
            else{
                int ans=query(1,1,n,x,y);
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}

