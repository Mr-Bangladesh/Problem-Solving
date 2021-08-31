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
    ll n,x;
    cin>>n>>x;
    ll a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    int i=1,j=n;
    int cnt=0;
    while(i<=j){
        if(a[j]+a[i]<=x){
            j--;
            i++;
            cnt++;
        }
        else{
            j--;
            cnt++;
        }
    }

    cout<<cnt<<endl;


    return 0;
}


