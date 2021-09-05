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

string s;
int n;
string f(string a,int i,char c){
    string b;
    for(int j=0;j<i;j++) b+=a[j];
    b+=c;
    for(int j=i;j<a.length();j++){
        b+=a[j];
    }
    return b;
}
void backtrack(int idx,string a){
    if(idx==n){
        cout<<a<<endl;
        return;
    }
    for(int i=0;i<=idx;i++){
        string tmp=f(a,i,s[idx]);
        backtrack(idx+1,tmp);
    }
}

int main()
{
    int cs=1;
    while(cin>>s){
        if(cs>1){
            printf("\n");
        }
        n=s.length();
        string tmp; tmp+=s[0];
        backtrack(1,tmp);
        cs++;
    }

    return 0;
}

