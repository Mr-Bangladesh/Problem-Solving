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
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n+1],b[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int l=1,r=n;
        for(int i=1;i<=min(n,m);i++){
            if(i%2){
                b[i]=a[l];
                l++;
            }
            else{
                b[i]=a[r];
                r--;
            }
        }
        if((min(n,m))%2){
            for(int i=min(n,m)+1;i<=n;i++){
                b[i]=a[l];
                l++;
            }
        }
        else{
            for(int i=min(n,m)+1;i<=n;i++){
                b[i]=a[r];
                r--;
            }
        }

        for(int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<endl;
    }

    return 0;
}

