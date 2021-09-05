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

int main()
{
    int l,g;
    while(scanf("%d %d",&l,&g),l||g){
        vector< pair<int,int> > v;
        int x,r;
        for(int i=1;i<=g;i++){
            scanf("%d %d",&x,&r);
            v.pb(mp(x-r,x+r));
        }
        sort(v.begin(),v.end());
        int cur=0,cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i].first>cur){
                break;
            }
            int mx=v[i].second;
            int j=i;
            while(j+1<v.size() && v[j+1].first<=cur){
                j++;
                mx=max(mx,v[j].second);
            }
            cnt++;
            cur=mx;
            if(cur>=l) break;
        }
        if(cur<l){
            cnt=-1;
        }
        else{
            cnt=g-cnt;
        }
        printf("%d\n",cnt);
    }

    return 0;
}

