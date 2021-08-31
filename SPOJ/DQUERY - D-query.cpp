#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct ff{
    int l,r,idx;
    ff(int a,int b,int c){
        l=a; r=b; idx=c;
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
    int t,n,m,x,y,w,k,q,p,cs;
    scanf("%d",&n);
    K=sqrt(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        v.pb(ff(x-1,y-1,i));
    }
    sort(v.begin(),v.end(),cmp);
    int l=0,r=-1;
    int ans[m]={0};
    for(auto it:v){
        while(r<it.r){
            r++;
            add(a[r]);
        }
        while(r>it.r){
            del(a[r]);
            r--;
        }
        while(l<it.l){
            del(a[l]);
            l++;
        }
        while(l>it.l){
            l--;
            add(a[l]);
        }
        ans[it.idx]=sum;
    }

    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
