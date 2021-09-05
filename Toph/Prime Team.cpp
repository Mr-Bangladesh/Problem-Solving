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

bool isprime(int n){
    if(n==1) return false;
    int x=sqrt(n);
    for(int i=2;i<=x;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(isprime(a[i])) x++;
        else y++;
    }
    int cnt=min(x,y);
    x-=cnt;
    cnt+=(x/2);
    cout<<cnt<<endl;

    return 0;
}


