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
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int tree[2000006],mn[2000006],mx[2000006];
void update(int n,int b,int e,int i,int v){
    if(i<b || i>e) return;
    if(i==b && b==e){
        tree[n]=v%2;
        mn[n]=v;
        mx[n]=v;
        return;
    }
    int mid=(b+e)/2;
    update(n*2,b,mid,i,v);
    update(n*2+1,mid+1,e,i,v);
    tree[n]=tree[n*2]+tree[n*2+1];
    mn[n]=min(mn[n*2],mn[n*2+1]);
    mx[n]=max(mx[n*2],mx[n*2+1]);
}

int cur;
int query(int n,int b,int e,int i,int j,int l,int r){
    if(i>e || j<b) return 0;
    //cout<<n<<" "<<b<<" "<<e<<" "<<mn[n]<<" "<<mx[n]<<" "<<l<<" "<<r<<endl;
    if(b>=i && e<=j && mn[n]>=l && mx[n]<=r){
        //cout<<"relavant "<<b<<" "<<e<<" "<<mn[n]<<" "<<mx[n]<<" "<<tree[n]<<endl;
        if(mn[n]>r || mx[n]<l)
        cur+=(e-b+1);
        return tree[n];
    }
    if(b==e){
        return 0;
    }
    int mid=(b+e)/2;
    int x=query(n*2,b,mid,i,j,l,r);
    int y=query(n*2+1,mid+1,e,i,j,l,r);
    return x+y;
}
int main()
{
    int q;
    //cin>>q;
    scanf("%d",&q);
    int n=0;
    int lim=500000;
    while(q--){
        int x;
        //cin>>x;
        scanf("%d",&x);
        if(x==1){
            int y;
            n++;
            //cin>>y;
            scanf("%d",&y);
            update(1,1,lim,n,y);
        }
        else{
            int k,l,r;
            //cin>>k>>l>>r;
            scanf("%d %d %d",&k,&l,&r);
            int cnt=n-k;
            int odd=query(1,1,lim,k+1,n,l,r);
            int even=cur-odd;
            cur=0;

            //cout<<cnt<<" "<<even<<" "<<odd<<endl;

            if(odd>even){
                //cout<<"Alice was ejected!"<<endl;
                printf("Alice was ejected!\n");
            }
            else if(even>odd){
                //cout<<"Bob was ejected!"<<endl;
                printf("Bob was ejected!\n");
            }
            else{
                //cout<<"No one was ejected!"<<endl;
                printf("No one was ejected!\n");
            }
        }
    }

    return 0;
}


