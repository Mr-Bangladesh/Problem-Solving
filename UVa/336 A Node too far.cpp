//UVa 336-A Node too far
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
map<int, vector<int> > Adj;
int bfs(int source,int ttl){
	map<int,int> dist,visited; // node er number jani na tai array na niye map nichi.
	int ans=1; // nije to nijeke visit korte parbei
	queue<int> q;
	q.push(source);
	dist[source]=0;
	visited[source]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:Adj[u]){
			if(visited[v]==0){
				visited[v]=1;
				dist[v]=dist[u]+1;
				q.push(v);
				if(dist[v]<=ttl){
					ans++;
				}
			}
		}
	}
	return ans;
}
int main(){
	int edge,test=1;
	while(cin>>edge){
		if(edge==0) break;
		int u,v;
		set<int> node;
		for(int i=0;i<edge;i++){
			cin>>u>>v;
			Adj[u].push_back(v);
			Adj[v].push_back(u);
			node.insert(u);
			node.insert(v);
		}
		int source,ttl;
		while(cin>>source>>ttl){
			if(source==0 && ttl==0) break;
			int ans=0;
			if(node.find(source)==node.end()){ ///source node ta graph e nai
				ans=node.size(); ///sobgula node e ans hobe
			}
			else{
				ans=node.size()-bfs(source,ttl); ///total theke ze koyta visit kora zay ta baad debo
			}
			cout<<"Case "<<test<<": "<<ans<<" nodes not reachable from node "<<source<<" with TTL = "<<ttl<<"."<<endl;
			test++;
		}
		Adj.clear(); ///prottek test case er jonno alada graph. aager ta clear kore dite hobe.
	}
	return 0;
}