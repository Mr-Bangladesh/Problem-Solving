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

bool check(int n,int x){
    int cnt=0;
    while(n%x==1){
        int d=n/x;
        cnt++;
        n--;
        n-=d;
    }
    //cout<<n<<" "<<x<<" "<<cnt<<endl;
    return (cnt==x);
}

int main()
{
    int n;
    while(scanf("%d",&n)){
        if(n<0) break;
        int m=n; n--;
        vector<int> v;
        int x=sqrt(n);
        for(int i=2;i<=x;i++){
            v.pb(i);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=-1;
        for(int x:v){
            if(check(m,x)){
                ans=x;
                break;
            }
        }
        if(ans==-1){
            printf("%d coconuts, no solution\n",m);
        }
        else{
            printf("%d coconuts, %d people and 1 monkey\n",m,ans);
        }
        //cout<<ans<<endl;
    }

    return 0;
}


