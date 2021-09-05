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

int main()
{
    vector<int> v;
    for(int i=0;i<=25;i++){
        v.pb(1<<i);
        //cout<<(1<<i)<<endl;
    }
    int n;
    while(scanf("%d",&n),n){
        int i=upper_bound(v.begin(),v.end(),n)-v.begin(); i--;
        int x=n-v[i];
        if(x==0){
            printf("%d\n",v[i]);
        }
        else{
            printf("%d\n",x*2);
        }
    }

    return 0;
}


