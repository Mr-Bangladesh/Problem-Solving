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
    //freopen("1.txt","r",stdin);
    int t,cs=1;
    while(scanf("%d",&t),t){
        map<int,int> idx;
        for(int i=1;i<=t;i++){
            int n,x;
            scanf("%d",&n);
            for(int j=1;j<=n;j++){
                scanf("%d",&x);
                idx[x]=i;
            }
        }
        deque<int> ans[t+2];
        string s;
        queue<int> q;
        map<int,int> mark;

        printf("Scenario #%d\n",cs++);

        while(cin>>s){
            if(s=="STOP") break;
            if(s=="ENQUEUE"){
                int x;
                scanf("%d",&x);
                if(!mark[idx[x]]){
                    q.push(idx[x]);
                    mark[idx[x]]=1;
                }
                ans[idx[x]].pb(x);
            }
            else{
                int u=q.front();
                printf("%d\n",ans[u].front());
                ans[u].pop_front();
                if(ans[u].size()==0){
                    mark[u]=0;
                    q.pop();
                }
            }
        }
        printf("\n");
    }

    return 0;
}

