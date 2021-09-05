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
    int t;
    scanf("%d",&t);
    getchar(); getchar();
    while(t--){
        string s;
        vector<int> a; a.pb(0);
        while(getline(cin,s)){
            if(s=="") break;
            int x=stoi(s);
            a.pb(x);
        }
        int n=a.size()-1;
        int dp[n+3]={0},lis=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]>a[i]){
                    if(dp[j]<dp[i]+1){
                        dp[j]=dp[i]+1;
                        lis=max(lis,dp[j]);
                    }
                }
            }
        }
        printf("Max hits: %d\n",lis+1);
        vector<int> ans;
        //cout<<"   "<<n<<endl;
        //for(int i=1;i<=n;i++) cout<<i<<" "<<dp[i]<<endl;
        for(int i=n;i>=1;i--){
            if(dp[i]==lis){
                ans.pb(a[i]);
                lis--;
            }
        }
        reverse(ans.begin(),ans.end());
        for(int u:ans) printf("%d\n",u);
        if(t) printf("\n");
    }

    return 0;
}

