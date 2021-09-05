/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
bool check(string a,string b){
    return lexicographical_compare(a.begin(),a.end(),b.begin(),b.end());
}
int main()
{
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n;
    vector<string>v1,v2;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[0]=='#'){
            v1.pb(s.substr(1));
        }
        else{
            v2.pb(s);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    //for(auto it:v1) cout<<it<<" "; cout<<endl;
    //for(auto it:v2) cout<<it<<" "; cout<<endl;

    vector<string> ans;
    n=v1.size(); m=v2.size();

    n=ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i];
        if(i<n-1) cout<<" ";
    }

    return 0;
}
