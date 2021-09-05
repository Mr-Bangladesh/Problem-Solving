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
    int n,cs=1;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        set<int> s;
        int cnt=0;
        while(1){
            int x=log2(n);
            int cur=2*(n-(1<<x))+1;
            //cout<<n<<" "<<cur<<endl;
            if(s.find(cur)!=s.end()){
                break;
            }
            s.insert(cur);
            cnt++;
            n=cur;
        }
        printf("Case %d: %d %d\n",cs++,cnt,n);
    }

    return 0;
}


