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
ll fx4[]={-1,0,0}; ll fy4[]={0,1,-1};
int n,m;
string s[8];
string a="IEHOVA#";
vector<string> ans;
void f(int u,int v,int idx){
    //cout<<u<<" "<<v<<" "<<s[u][v]<<endl;
    for(int i=0;i<3;i++){
        int x=u+fx4[i]; int y=v+fy4[i];
        if(x>=0 && x<n && y>=0 && y<m && s[x][y]==a[idx]){
            if(i==0){
                ans.pb("forth");
            }
            else if(i==1){
                ans.pb("right");
            }
            else{
                ans.pb("left");
            }
            f(x,y,idx+1);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int s1,s2,t1,t2;
        for(int i=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<m;j++){
                if(s[i][j]=='@'){
                    s1=i; s2=j;
                }
                if(s[i][j]=='#'){
                    t1=i; t2=j;
                }
            }
        }
        f(s1,s2,0);
        int x=ans.size();
        for(int i=0;i<x;i++){
            cout<<ans[i];
            if(i<x-1) printf(" ");
        }
        printf("\n");
        ans.clear();
    }

    return 0;
}

