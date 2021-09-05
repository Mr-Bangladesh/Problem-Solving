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
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

vector<int> f(vector<int> v,int n){
    vector<int> lis,len;
    for(int i=0;i<n;i++){
        int pos=upper_bound(lis.begin(),lis.end(),v[i])-lis.begin();
        if(pos==lis.size()){
            lis.pb(v[i]);
        }
        else{
            lis[pos]=v[i];
        }
        len.pb(pos+1);
    }
    return len;
}

int main()
{
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> v;
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            v.pb(x);
        }
        int ans=INT_MAX;
        scanf("%d",&x);
        vector<int> tmp=f(v,n);
        for(int i=0;i<n;i++){
            if(tmp[i]==x){
                ans=min(ans,v[i]);
            }
        }
        if(ans==INT_MAX){
            printf("Case %d: %d\n",cs++,-1);
        }
        else{
            printf("Case %d: %d\n",cs++,ans);
        }
    }

    return 0;
}


