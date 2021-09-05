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
    int n,m;int cs=1;
    while(scanf("%d %d",&n,&m),n||m){
        int x=n-m;
        if(x<1){
            printf("Case %d: 0\n",cs++);
            continue;
        }
        int d=x/m; if(x%m) d++;
        if(d>26){
            printf("Case %d: impossible\n",cs++);
        }
        else{
            printf("Case %d: %d\n",cs++,d);
        }
    }

    return 0;
}


