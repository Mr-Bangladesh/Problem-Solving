/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
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
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
int n,m,k;
int a[22][22];
int dist[22][22][22][22];

void bfs(int s1,int s2){
    queue< pair<int,int> > q;
    q.push(mp(s1,s2));
    int mark[22][22];
    memset(mark,0,sizeof(mark));
    dist[s1][s2][s1][s2]=0;
    //cout<<s1<<" "<<s2<<" "<<s1<<" "<<s2<<endl;
    mark[s1][s2]=1;
    while(!q.empty()){
        int u1=q.front().first; int u2=q.front().second; q.pop();
        //cout<<u1<<" "<<u2<<endl;
        for(int i=0;i<4;i++){
            int v1=u1+fx4[i];
            int v2=u2+fy4[i];
            
            if(v1>0 && v1<=n && v2>0 && v2<=m && a[v1][v2]==1 && mark[v1][v2]==0){
                mark[v1][v2]=1;
                q.push(mp(v1,v2));
                dist[s1][s2][v1][v2]=dist[s1][s2][u1][u2]+1;
            }
        }
    }
}
int main()
{
	while(scanf("%d %d %d",&k,&n,&m)!=EOF){
		vector< pair<int,int> > source;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]==0){
					source.pb(mp(i,j));
				}
			}
		}
		
		for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=n;k++){
                    for(int l=1;l<=m;l++){
                        dist[i][j][k][l]=-1;
                    }
                }
            }
        }
		
		for(auto it:source){
			bfs(it.first,it.second);
		}
		int x,y;
		int res=INT_MAX;
		
		vector< pair<int,int> > input;
		
		for(int i=1;i<=k;i++){
			scanf("%d %d",&x,&y);
			x++; y++;
			input.pb(mp(x,y));
		}
		
		for(auto it:source){
			int u=it.first,v=it.second;
			int cur=0; bool check=true;
			for(auto x:input){
				int d=dist[u][v][x.first][x.second];
				if(d==-1){
					check=false;
					break;
				}
				cur=max(cur,d);
			}
			if(check) res=min(res,cur);
		}
		
		if(res==INT_MAX) res=-1;
		printf("%d\n",res);
	}

    return 0;
}

