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
#define   MAX 500006
#define   pb     push_back
#define   mp     make_pair
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))

vector<ll>prime;
bool mark[10000007];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
ordered set pair
	template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

*/

int main(){
    int test;
    scanf("%d", &test);
    for(int cs = 1; cs <= test; cs++){
       int n;
       scanf("%d",&n);
       
       if(n%2==0){
       	printf("-1\n");
       	continue;
       }
       
       int a[n+1][n+1];
       int b[n+1];
       
       memset(a,0,sizeof(a));
       int cur=1;
       for(int i=1;i<=n;i+=2){
       		b[i]=cur;
       		cur++;
       }
       
       for(int i=2;i<=n;i+=2){
       		b[i]=cur;
       		cur++;
       }
       
       //for(int i=1;i<=n;i++) cout<<b[i]<<" ";
       
       for(int i=1;i<=n;i++){
       		//for(int j=1;j<=n;j++) cout<<b[j]<<" ";cout<<endl;
       		for(int j=1;j<=n;j++){
       			a[i][j]=b[j];
       		}
       		
       		int c[n+1];
       		for(int j=1;j<=n;j++) c[j]=b[j];
       		
       		for(int j=1;j<n;j++) b[j]=c[j+1];
       		b[n]=c[1];
       		
       }
       
       for(int i=1;i<=n;i++){
       	for(int j=1;j<=n;j++) printf("%d ",a[i][j]); printf("\n");
       }
        
    }
    return 0;
}