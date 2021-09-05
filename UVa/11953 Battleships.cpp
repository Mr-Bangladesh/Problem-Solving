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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int fx[]={1,-1,0,0,-1,1,-1,1};
int fy[]={0,0,1,-1,-1,1,1,-1};
string s[102];
int mark[102][102];
int n;

void dfs(int u1,int u2){
    mark[u1][u2]=1;
    //cout<<"visited "<<u1<<" "<<u2<<endl;
    for(int i=0;i<4;i++){
        int v1=u1+fx[i];
        int v2=u2+fy[i];
        if(v1>=0 && v1<n && v2>=0 && v2<n && mark[v1][v2]==0 && s[v1][v2]!='.'){
            dfs(v1,v2);
        }
    }
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        scanf("%d",&n);
        vector< pair<int,int> > v;
        for(int i=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<n;j++){
                if(s[i][j]=='x'){
                    v.pb(mp(i,j));
                }
            }
        }
        int cnt=0;
        for(auto it:v){
            int x=it.first; int y=it.second;
            if(!mark[x][y]){
                cnt++;
                dfs(x,y);
            }
        }
        printf("Case %d: %d\n",cs,cnt);

        memset(mark,0,sizeof(mark));
    }

    return 0;
}


