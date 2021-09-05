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

bool f(int n,int k){
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    int u;
    while(!q.empty()){
        u=q.front(); q.pop();
        for(int i=1;i<k;i++){
            int v=q.front();
            q.push(v);
            q.pop();
        }
    }
    if(u==13) return true;
    else return false;
}

int main()
{
    int n;
    while(scanf("%d",&n),n){
        int m=1;
        for(int m=1;;m++){
            if(f(n,m)){
                printf("%d\n",m);
                break;
            }
        }
    }

    return 0;
}


