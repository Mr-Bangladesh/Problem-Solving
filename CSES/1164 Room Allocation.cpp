/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
///order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
struct ff{
    int x,y,idx;
    ff(int a,int b,int c){
        x=a; y=b;idx=c;
    }
};
bool cmp(ff a,ff b){
    return a.x<b.x;
}
int main()
{
    int n;
    cin>>n;
    int x,y;
    vector<ff> v;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        v.pb(ff(y,x,i));
    }
    sort(v.begin(),v.end(),cmp);

    for(auto it:v) cout<<it.x<<" "<<it.y<<" "<<it.idx<<endl;

    int res[n+1]={0};
    oset< pair<int,int> > s;
    int col=0;
    for(int i=0;i<n;i++){
        int k=v[i].idx;
        int cur=v[i].y;
        s.insert(mp(v[i].x,k));
        int it=s.order_of_key(mp(cur,0)); it--;
        //cout<<"cur "<<cur<<" "<<it<<endl;
        //for(auto x:s) cout<<x.first<<" "<<x.second<<endl;

        //if(it==0 && (*s.find_by_order(it)).first>=cur){
        if(it==-1){
            col++;
            res[k]=col;
        }
        else{
            //cout<<k<<"   "<<(*s.find_by_order(it)).second<<endl;
            res[k]=res[(*s.find_by_order(it)).second];
        }
    }

    cout<<col<<endl;
    for(int i=1;i<=n;i++) cout<<res[i]<<" "; cout<<endl;

    return 0;
}


