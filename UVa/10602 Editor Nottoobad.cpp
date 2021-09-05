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
int f(string a,string b){
    int x=a.length(),y=b.length();
    int cnt=0;
    for(int i=0;i<min(x,y);i++){
        if(a[i]!=b[i]) break;
        cnt++;
    }
    return cnt;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        string s[n+1];
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        queue<int> q;
        q.push(1);
        vector<int> ans;
        bool mark[n+1]={0};
        int total=s[1].length();
        while(!q.empty()){
            int u=q.front(); q.pop();
            //cout<<u<<" "<<s[u]<<endl;
            ans.pb(u);
            mark[u]=1;
            int mx=-1,idx=-1,cost=-1;
            for(int i=1;i<=n;i++){
                if(i==u || mark[i]) continue;
                int x=f(s[u],s[i]);
                int c=s[i].length()-x;
                if(x>mx){
                    mx=x;
                    idx=i;
                    cost=c;
                }
            }
            if(mx==-1) break;
            total+=cost;
            q.push(idx);
        }
        printf("%d\n",total);
        for(int x:ans){
            cout<<s[x]<<endl;
        }
    }

    return 0;
}

