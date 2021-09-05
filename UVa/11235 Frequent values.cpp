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
int a[100005],t[400005];
map<int,int> cnt,st;
void build(int n,int b,int e){
    if(b==e){
        t[n]=cnt[a[b]];
        //cout<<"node "<<n<<" "<<t[n]<<endl;
        return;
    }
    int mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    t[n]=max(t[n*2],t[n*2+1]);
    //cout<<n<<" "<<t[n]<<endl;
}
int query(int n,int b,int e,int i,int j){
    if(b>j || e<i) return 0;
    if(b>=i && e<=j){
        return t[n];
    }
    int mid=(b+e)/2;
    int x=query(n*2,b,mid,i,j);
    int y=query(n*2+1,mid+1,e,i,j);
    return max(x,y);
}
int main()
{
    int n,q,x,y;
    while(scanf("%d",&n),n){
        scanf("%d",&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
            if(i==1){
                st[a[i]]=1;
            }
            else if(a[i]==a[i-1]){
                st[a[i]]=st[a[i-1]];
            }
            else{
                st[a[i]]=i;
            }
        }
        build(1,1,n);
//        for(int i=1;i<=n;i++){
//            cout<<i<<" "<<a[i]<<" "<<st[a[i]]<<" "<<cnt[a[i]]<<endl;
//        }
        while(q--){
            scanf("%d %d",&x,&y);
            if(a[x]==a[y]){
                printf("%d\n",y-x+1);
                continue;
            }
            int left=cnt[a[x]]-(x-st[a[x]]);
            int right=y-st[a[y]]+1;
            x+=left; y-=right;
            //cout<<left<<" "<<right<<endl;
            //cout<<x<<" "<<y<<endl;
            int mid=query(1,1,n,x,y);
            //cout<<left<<" "<<mid<<" "<<right<<endl;
            printf("%d\n",max(left,max(mid,right)));
        }
        memset(t,0,sizeof(t));
        cnt.clear();
        st.clear();
    }

    return 0;
}

