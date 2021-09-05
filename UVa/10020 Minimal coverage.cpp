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
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--){
        int n,x,y;
        vector< pair<int,int> >  v;
        scanf("%d",&n);
        while(scanf("%d %d",&x,&y),x||y){
            v.pb(mp(x,y));
        }
        sort(v.begin(),v.end(),cmp);
        bool check=true;
        int cur=0;
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(v[i].first>cur){
                check=false; break;
            }
            int mx=v[i].second,idx=i;
            int j=i;
            while(j+1<v.size() && v[j+1].first<=cur){
                j++;
                if(v[j].second>mx){
                    mx=v[j].second; //cout<<mx<<" "<<idx<<endl;
                    idx=j;
                }
            }
            cur=mx;
            ans.pb(idx);
            i=j;
            if(cur>=n) break;
        }
        if(!check || cur<n){
            printf("0\n\n");
            continue;
        }
        printf("%d\n",ans.size());
        for(int i:ans){
            printf("%d %d\n",v[i].first,v[i].second);
        }
        printf("\n");
    }

    return 0;
}

