#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
using namespace std;
using namespace __gnu_pbds;

#define   ll long long
#define   MAX 1005
#define   pb     push_back
#define   mp     make_pair
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define INF 9223372036854775801
vector<ll>prime;
bool mark[10000007];
//void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
ordered set pair
	template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

*/

struct edge{
	ll u,v,w;
	edge(ll a,ll b,ll c){
		u=a; v=b; w=c;
	}
};
bool cmp(edge a,edge b){
	return a.w<b.w;
}

vector< pair<ll,ll> > G[MAX];
ll Vis[MAX];
void check(int s,int n){
	for(int i=1;i<=n;i++){
		Vis[i]=0;
	}
	Vis[s]=1;
	queue<ll> q;
	q.push(s);
	
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(auto it:G[u]){
			ll v=it.first;
			if(!Vis[v]){
				Vis[v]=1;
				q.push(v);
			}
		}
	}
}


struct node{
	ll At,Cost;
	node(ll a,ll b){
		At=a; Cost=b;
	}
	bool operator<(node other) const{
		return Cost>other.Cost;
	}
};

ll dist[MAX],M[MAX];
pair<ll,ll> dijkstra(ll s,ll n){
	for(int i=1;i<=n;i++){
		dist[i]=INF; M[i]=0;
	}
	dist[s]=0;
	priority_queue<node> pq; pq.push(node(s,0));
	M[s]=1;
	
	ll cnt=1,cur=INF;
	
	while(!pq.empty()){
		ll u=pq.top().At; ll Cost=pq.top().Cost; pq.pop();
		for(auto it:G[u]){
			ll v=it.first; ll w=it.second;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				pq.push(node(v,dist[v]));
			}
			if(!M[v]){
					cnt++;
					M[v]=1;
			}
			else if(v==s){
				cur=min(cur,dist[u]+dist[v]+w);
			}
		}
	}
	return mp(cnt,cur);
}

// ll dist[MAX];
// pair<ll,ll> bfs(ll s,ll n){
	// for(int i=1;i<=n;i++){
		// dist[i]=INF;
	// }
	// dist[s]=0;
// 	
	// ll cnt=1;
	// ll cur=INF;
	// queue<ll> q;
	// q.push(s);
	// while(!q.empty()){
		// ll u=q.front(); q.pop();
// 		
		// for(auto it:G[u]){
			// ll v=it.first; ll w=it.second;
// 			
			// if(dist[v]==INF){
				// dist[v]=dist[u]+w;
				// q.push(v);
				// cnt++;
			// }
			// else if(v==s){
				// cur=min(cur,dist[v]+dist[u]+w);
			// }
// 			
		// }
	// }
	// return mp(cnt,cur);
// }

int main(){
    int test;
    scanf("%d", &test);
    for(int cs = 1; cs <= test; cs++){
        ll n,m,s;
        scanf("%lld %lld %lld",&n,&m,&s);
        set< pair<ll,ll> > Mark;
        vector<edge> V;
        
        ll x,y,w;
        
        for(int i=1;i<=m;i++){
        	scanf("%lld %lld %lld",&x,&y,&w);
        	V.pb(edge(x,y,w));
        }
        
        sort(V.begin(),V.end(),cmp);
        
        for(auto it:V){
        	x=it.u; y=it.v; w=it.w;
        	if(Mark.find(mp(x,y))==Mark.end()){
        		G[x].pb(mp(y,w));
        		Mark.insert(mp(x,y));
        		//cout<<x<<" "<<y<<endl;
        		//G[y].pb(mp(x,w));
        	}
        }
        
        check(s,n);
        
        vector< pair<ll,ll> > temp;
        ll maxres=0;
        for(int i=1;i<=n;i++){
        	if(!Vis[i]) continue;
        	
        	// if(Vis[i]){
//         		
        	// }
        	
        	pair<ll,ll> cur=dijkstra(i,n);
        	if(cur.second==INF) continue;
        	
        	maxres=max(maxres,cur.first);
        	
        	temp.pb(mp(cur.first,cur.second+1));
        	//cout<<i<<" "<<cur.first<<" "<<cur.second+1<<endl;
        }
        ll ans=INF;
        //cout<<maxres<<endl;
        for(auto it:temp){
        	if(it.first==maxres){
        		ans=min(ans,it.second);
        	}
        }  
        
        if(maxres==0){
        	ans=0;
        }
        
        printf("%lld %lld\n",maxres,ans);
        
        
        for(int i=1;i<MAX;i++){
        	G[i].clear();
        	Vis[i]=0;
        }
    }
    return 0;
}