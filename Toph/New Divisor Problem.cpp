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
ll nod[1000005];
void init(){
    for(int i=1;i<=1000000;i++){
        nod[i]=1;
    }
    for(int i=2;i<=1000000;i++){
        for(int j=i;j<=1000000;j+=i){
            nod[j]++;
        }
    }
}
struct ff{
    ll l,r,k,idx;
    ff(ll a,ll b,ll c,ll d){
        l=a; r=b; k=c; idx=d;
    }
};
ll K;
bool cmp(ff a,ff b){
    ll a1=a.l/K; ll b1=b.l/K;
    if(a1==b1) return a.r<b.r;
    return a1<b1;
}
ll a[100005],cnt[1000005],mark[1000005];
void add(ll x){
    mark[x]++;
    if(mark[x]==1){
        cnt[nod[x]]++;
    }
}
void del(ll x){
    mark[x]--;
    if(mark[x]==0){
        cnt[nod[x]]--;
    }
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    init();
    cin>>t;
    for(cs=1;cs<=t;cs++){
        cin>>n;
        K=sqrt(n);
        for(int i=1;i<=n;i++) cin>>a[i];
        cin>>q;
        vector<ff> v;
        for(int i=1;i<=q;i++){
            cin>>x>>y>>k;
            v.pb(ff(x,y,k,i));
        }
        sort(v.begin(),v.end(),cmp);
//        for(auto it:v){
//            cout<<it.l<<" "<<it.r<<" "<<it.k<<" "<<it.idx<<endl;
//        }
        ll ans[q+3]={0};
        ll l=1,r=0;
        for(ff it:v){
            ll l1=it.l; ll r1=it.r; ll k1=it.k; ll idx=it.idx;
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
            ans[idx]=cnt[k1];
        }
        cout<<"Case "<<cs<<":"<<endl;
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        memset(mark,0,sizeof(mark));
    }

    return 0;
}

