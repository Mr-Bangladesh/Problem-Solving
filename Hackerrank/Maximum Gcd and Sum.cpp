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

int a[1000004],b[1000004],da[1000004],db[1000004];

int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        b[x]++;
    }

    for(int i=1;i<=1e6;i++){
        for(int j=i;j<=1e6;j+=i){
            if(a[j]){
                da[i]=max(da[i],j);
            }
            if(b[j]){
                db[i]=max(db[i],j);
            }
        }
    }

    for(int i=1e6;i>=1;i--){
        if(da[i] && db[i]){
            printf("%d\n",da[i]+db[i]);
            return 0;
        }
    }

    return 0;
}

