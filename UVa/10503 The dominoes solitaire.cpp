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
int n,m,x,y,s,e;
bool check;
vector< pair<int,int> > dom;
void backtrack(int idx,int cur,int mask){
    //cout<<idx<<" "<<cur<<" "<<mask<<endl;
    if(idx==n){
        check=cur==e;
        return;
    }
    for(int i=0;i<m;i++){
        if(!(mask&(1<<i)) && dom[i].first==cur){
            mask|=(1<<i);
            backtrack(idx+1,dom[i].second,mask);
            mask^=(1<<i);
        }
    }
}
int main()
{
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        scanf("%d %d %d %d",&x,&s,&e,&y);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            if(x<=y) dom.pb({x,y});
            else dom.pb({y,x});
        }
        backtrack(0,s,0);
        if(check) printf("YES\n");
        else printf("NO\n");
        dom.clear();
        check=false;
    }

    return 0;
}

