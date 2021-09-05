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
vector<int> v;
int f(int i,int mask,int h,int n){
    //cout<<i<<" "<<mask<<endl;
    if(i<0){
        //cout<<"candidte "<<mask<<endl;
        int cnt=0;
        for(int j=0;j<n;j++){
            if(mask&(1<<j)) cnt++;
        }
        if(cnt==h){
                //cout<<mask<<endl;
            v.pb(mask);
            return 1;
        }
        else return 0;
    }
    int x=f(i-1,mask|(1<<i),h,n);
    int y=f(i-1,mask,h,n);
    return x+y;
}
int main()
{
    int  t;
    scanf("%d",&t);
    while(t--){
        int n,h;
        scanf("%d %d",&n,&h);
        f(n-1,0,h,n);
        sort(v.begin(),v.end());
        for(int x:v){
            string s;
            for(int i=0;i<n;i++){
                if(x&(1<<i)){
                    s+='1';
                }
                else s+='0';
            }
            reverse(s.begin(),s.end());
            cout<<s<<endl;
        }
        if(t) printf("\n");
        v.clear();
    }

    return 0;
}

