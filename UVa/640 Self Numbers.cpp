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

int f(int n){
    int s=0;
    while(n){
        s+=(n%10);
        n/=10;
    }
    return s;
}

int main()
{
    set<int> s;
    for(int i=1;i<=1e6;i++) s.insert(i);

    for(int i=1;i<=1e6;i++){
        int x=i+f(i);
        s.erase(x);
    }
    //cout<<s.size()<<endl;
    for(int x:s){
        printf("%d\n",x);
    }

    return 0;
}


