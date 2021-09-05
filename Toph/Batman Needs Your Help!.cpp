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

int lps[5000000];

string f(string str)
{
    string temp = str + '?';
    reverse(str.begin(), str.end());
    temp += str;
    int n = temp.length();
    for (int i = 1; i <= n; i++) {
        int len = lps[i - 1];
        while (len > 0
               && temp[len] != temp[i]) {
            len = lps[len - 1];
        }
        if (temp[i] == temp[len]) {
            len++;
        }
        lps[i] = len;
    }
    return temp.substr(0, lps[n - 1]);
}

int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();

    reverse(b.begin(),b.end());

    string s;
    int l=-1;
    for(int i=0;i<min(n,m);i++){
        if(a[i]!=b[i]){
            break;
        }
        l=i;
    }

    memset(lps,0,sizeof(lps));
    string a1=a.substr(l+1,n);
    memset(lps,0,sizeof(lps));
    string b1=b.substr(l+1,m);

    string x=f(a1);
    string y=f(b1);

    string ans="";

    for(int i=0;i<=l;i++) ans+=a[i];

    if(x.length()>y.length()){
        ans+=x;
    }
    else if(y.length()>x.length()){
        ans+=y;
    }
    else{
        ans+=min(x,y);
    }

    for(int i=l;i>=0;i--) ans+=b[i];

    cout<<ans<<endl;

    return 0;
}


