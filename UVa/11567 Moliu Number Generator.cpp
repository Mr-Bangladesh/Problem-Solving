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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

bool f(ll n){
    int x=n+1;
    int y=n-1;
    int cnt=0;
    while(x && x%2==0){
        x/=2; cnt++;
    }
    while(y && y%2==0){
        y/=2; cnt--;
    }
    if(cnt>0) return true;
    return false;
}


int main()
{
    //freopen("1.txt","r",stdin);
    ll n;
    while(scanf("%lld",&n)!=EOF){
        int cnt=0;
        while(n!=0){
            //cout<<n<<endl;
            if(n%2==0){
                n/=2;
            }
            else{
                if(n>3 && f(n)){
                    n++;
                }
                else{
                    n--;
                }
            }
            cnt++;
            //cout<<n<<endl;
        }
        printf("%d\n",cnt);
    }

    return 0;
}

