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

map<ll,ll> cnt;

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;

    ll a[n+1],b[m+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        cnt[b[i]]++;
    }
    sort(b+1,b+m+1);
    sort(a+1,a+n+1);

    int i=1,j=1;
    int cnt=0;
    while(i<=n && j<=m){
        if(b[j]>=a[i]-k && b[j]<=a[i]+k){
            cnt++;
            i++;
            j++;
        }
        else if(b[j]<a[i]-k){
            j++;
        }
        else if(b[j]>a[i]+k){
            i++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}


