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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
bool f(int a,int b){
    vector<int> u,v;
    int x=a,y=b;
    while(x){
        u.pb(x%10);
        x/=10;
    }
    while(y){
        v.pb(y%10);
        y/=10;
    }
    reverse(u.begin(),u.end());
    reverse(v.begin(),v.end());

    int a1=a,b1=b;
    for(int i:v){
        a1=a1*10+i;
    }
    for(int i:u){
        b1=b1*10+i;
    }
    //cout<<a<<" "<<b<<" "<<a1<<" "<<b1<<endl;
    if(a1<b1) return true;
    return false;
}
string tostring(int n){
    vector<int> v;
    while(n){
        v.pb(n%10);
        n/=10;
    }
    string s="";
    reverse(v.begin(),v.end());
    for(int i:v){
        s+=(i+48);
    }
    return s;
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
        int a[n+1];
        int x=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=n;j>i;j--){
                if(!f(a[j],a[j-1])){
                    //cout<<a[j]<<" "<<a[j-1]<<endl;
                    swap(a[j],a[j-1]);
                }
            }
        }
        string ans="";
        for(int i=1;i<=n;i++){
            string x=tostring(a[i]);
            ans+=x;
        }
        if(ans.size()==0) cout<<0<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}

