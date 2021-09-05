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
    int n,m;
    while(scanf("%d %d",&n,&m),n||m){
        vector<int> v;
        for(int i=1;i<=n;i++) v.pb(i);
        int a[m+1],b[m+1],c[m+1];
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
            a[i]++; b[i]++;
        }
        int cnt=0;
        int idx[n+2]={0};
        for(int i=1;i<=n;i++) idx[i]=i;
        bool check=true;
        for(int i=1;i<=m;i++){
            int d=abs(c[i]);
            if(abs(idx[b[i]]-idx[a[i]])!=d){
                check=false; break;
            }
        }
        if(check) cnt++;

        while(next_permutation(v.begin(),v.end())){
            for(int i=0;i<v.size();i++) idx[v[i]]=i+1;
            check=true;
            for(int i=1;i<=m;i++){
                int d=abs(c[i]);
                if(abs(idx[b[i]]-idx[a[i]])!=d){
                    check=false; break;
                }
            }
            if(check) cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}

