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

    for(int cs=1;cs<=t;cs++){
        int n,m,a,b;
        scanf("%d %d %d %d",&n,&m,&a,&b);
        int cnt[27]={0};
        set<int> ltr;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                ltr.insert(s[j]-64);
                cnt[s[j]-64]++;
            }
        }
        int mx=0,id=1;
        for(auto it:ltr){
            if(cnt[it]>mx){
                mx=cnt[it];
                id=it;
            }
        }
        int x=0;
        for(auto it:ltr){
            if(cnt[it]==mx) x++;
        }

        //cout<<id<<" "<<mx<<" "<<x<<endl;

        int ans=x*mx*a + (n*m-mx*x)*b;
        printf("%d\n",ans);
    }

    return 0;
}

