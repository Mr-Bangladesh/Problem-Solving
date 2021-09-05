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
set<int> s;
bool check=true;
void del(int x,int y){
    if(!s.size()){
        check=false; return;
    }
    auto it1=s.lower_bound(x); auto it2=s.upper_bound(y);
    vector<int> v;
    while(it1!=it2){
        v.pb(*it1);
        it1++;
    }
    int len=v.size();
    if(!len){
        check=false; return;
    }
    if(v[0]-x>1 || y-v.back()>1){
        check=false; return;
    }
    for(int x:v){
        s.erase(x);
    }
    //cout<<"delete"<<endl;
    //for(int x:v) cout<<x<<" "; cout<<endl;
    //cout<<"set"<<endl;
    //for(auto it:s) cout<<it<<" "; cout<<endl;
}
ll lim=1e6;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)){
        if(n==0 && m==0) break;

        for(int i=0;i<=lim;i++) s.insert(i);

        for(int i=1;i<=n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            if(!check) continue;
            del(x,y);
            //cout<<"check "<<check<<endl;
        }
        for(int i=1;i<=m;i++){
            int x,y,f;
            scanf("%d %d %d",&x,&y,&f);
            if(!check) continue;
            while(x<=lim && y<=lim){
                del(x,y);
                x+=f;
                y+=f;
            }
        }
        if(check) printf("NO CONFLICT\n");
        else printf("CONFLICT\n");

        s.clear();
        check=true;
    }

    return 0;
}

