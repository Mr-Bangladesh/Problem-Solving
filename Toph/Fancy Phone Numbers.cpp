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

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		char s[12];
		scanf("%s",s);
		int len=strlen(s);
		
		bool check=false;
		
		for(int i=0;i<len-3;i++){
			if(s[i]==s[i+1]-1 && s[i+1]==s[i+2]-1 && s[i+2]==s[i+3]-1){
				check=true;
				break;
			}
		}
		if(check){
			printf("Fancy\n");
			continue;
		}
		for(int i=0;i<len-2;i++){
			if(s[i]==s[i+1] && s[i]==s[i+2]){
				check=true;
				break;
			}
		}
		if(check){
			printf("Fancy\n");
			continue;
		}
		int cnt=0;
		for(int i=0;i<len-1;i++){
			if(s[i]==s[i+1]){
				cnt++;
				i++;
			}
		}
		if(cnt>=2){
			printf("Fancy\n");
			continue;
		}
		int freq[10]={0};
		for(int i=0;i<len;i++){
			freq[s[i]-'0']++;
		}
		
		for(int i=0;i<10;i++){
			if(freq[i]>=5){
				check=true;
				break;
			}
		}
		
		if(check){
			printf("Fancy\n");
			continue;
		}
		
		printf("Not Fancy\n");
	}

    return 0;
}

