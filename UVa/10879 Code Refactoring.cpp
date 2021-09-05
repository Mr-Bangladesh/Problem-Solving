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
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        int x=sqrt(n);
        int a,b,c,d;
        for(int i=2;i<=x;i++){
            if(n%i) continue;
            int j=n/i;
            a=i; b=j;
            int y=sqrt(j);
            for(int k=2;k<=y;k++){
                if(j%k) continue;
                int l=j/k;
                c=i*k; d=l;
                break;
            }
            break;
        }
        printf("Case #%d: %d = %d * %d = %d * %d\n",cs,n,a,b,c,d);
    }

    return 0;
}


