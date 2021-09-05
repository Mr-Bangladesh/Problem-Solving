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

int main()
{
    string s;
    while(cin>>s){
        if(s=="END") break;
        stringstream input(s);
        double n;
        input>>n;
        if(n==0 || n==1){
            cout<<"MEMBER"<<endl;
            continue;
        }
        bool check=true;
        for(int i=0;i<=6;i++){
            double x=n*3.0;
            int r=(int)floor(x);
            if(r==1){
                check=false; break;
            }
            n=x-(double)r;
        }
        if(check) cout<<"MEMBER"<<endl;
        else cout<<"NON-MEMBER"<<endl;
    }

    return 0;
}

