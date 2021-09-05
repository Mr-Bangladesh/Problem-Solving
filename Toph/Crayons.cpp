/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair

struct ff{
    int id,l,r,idx;
    ff(int _id,int a,int b,int c){
        id=_id;l=a; r=b; idx=c;
    }
};
vector<ff> v;
int K;
bool cmp(ff a,ff b){
    int b1=a.l/K; int b2=b.l/K;
    if(b1==b2) return a.r<b.r;
    return b1<b2;
}
int a[100005];
int sum=0;
unordered_map<int,int> cnt;
void add(int x){
    cnt[x]++;
    if(cnt[x]==1) sum++;
}
void del(int x){
    cnt[x]--;
    if(cnt[x]==0) sum--;
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    int t,n,m,x,y,w,k,q,p,cs;
    int c[6];
    for(int i=1;i<=5;i++){
        scanf("%d",&c[i]);
    }
    scanf("%d %d",&n,&m);
    K=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    //getchar();
    for(int i=0;i<m;i++){
        char c[1];
        getchar();
        scanf("%s",c);
        scanf("%d %d",&x,&y);
        //cout<<c<<" "<<x<<" "<<y<<endl;
        v.pb(ff(c[0]-64,x,y,i));
    }
    sort(v.begin(),v.end(),cmp);

    //for(auto it:v) cout<<it.l<<" "<<it.r<<" "<<it.idx<<endl;

    int l=1,r=0;
    int ans[m]={0};
    for(int i=0;i<m;i++){
        //cout<<it.l<<" "<<it.r<<" "<<it.idx<<endl;
        int l1=v[i].l; int r1=v[i].r; int id=v[i].id; int idx=v[i].idx;
        while(r<r1){
            r++;
            add(a[r]);
        }
        while(r>r1){
            del(a[r]);
            r--;
        }
        while(l<l1){
            del(a[l]);
            l++;
        }
        while(l>l1){
            l--;
            add(a[l]);
        }
        //cout<<l1+1<<" "<<r1+1<<" "<<sum<<endl;
        if(sum>=c[id]){
            ans[idx]=1;
        }
    }

    for(int i=0;i<m;i++){
        if(ans[i]) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
