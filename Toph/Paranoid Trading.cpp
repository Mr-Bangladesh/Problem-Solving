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

int a[1004];
int n;
ll f(int cur,int sell,int last,int lastprofit){
    if(cur>n) return 0;
    ll ans=0;
    if(last==-1){
        ans=max(f(cur+1,1,a[cur],0) , f(cur+1,0,last,lastprofit));
    }
    else{
        if(sell){
            if(a[cur]-last==1 || a[cur]-last==-1){

            }
        }
        else{

        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
    }

    return 0;
}


