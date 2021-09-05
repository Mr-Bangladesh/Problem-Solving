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

int main()
{
    //freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        ll len,n;
        scanf("%lld %lld",&len,&n);

        len*=100;

        queue<ll> left,right;
        vector< pair<ll,string> > v;
        for(int i=1;i<=n;i++){
            string s;ll x;
            scanf("%lld",&x); cin>>s;
            if(s=="left") left.push(x);
            else right.push(x);
        }
        int ferry=1,cnt=0;
        while(left.size() || right.size()){
                //cout<<"ferry "<<ferry<<" "<<cnt<<endl;
            if(ferry==1){
                int sum=0;
                while(!left.empty()){
                    int u=left.front();
                    if(sum+u<=len){
                        sum+=u;
                        left.pop(); //cout<<"takes from left "<<u<<endl;
                    }
                    else break;
                }
                if(sum){
                    cnt++;
                    ferry=2; //cout<<"moves right "<<sum<<endl;
                }
                else if(right.size()){
                    cnt++;
                    ferry=2;
                }
            }
            else{
                int sum=0;
                while(!right.empty()){
                    int u=right.front();
                    if(sum+u<=len){
                        sum+=u;
                        right.pop();
                    }
                    else break;
                }
                if(sum){
                    cnt++;
                    ferry=1; //cout<<"moves left "<<sum<<endl;
                }
                else if(left.size()){
                    cnt++;
                    ferry=1;
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}

