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
string f(string a,string b){
    int n=a.length(); int m=b.length();
    int mx=0;
    for(int i=n-1;i>=0;i--){
        int j=0,k=i; bool check=true;
        for(;k<n;k++){
            if(a[k]!=b[j]){
                check=false;
                break;
            }
            j++;
        }
        if(check){
            if(j>mx){
                mx=j;
            }
        }
    }
    string s=a;
    for(int i=mx;i<m;i++) s+=b[i];
    return s;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        string s[n];
        vector<int> v;
        for(int i=0;i<n;i++){
            cin>>s[i]; v.pb(i);
        }
        int mn=INT_MAX;
        do{
//                cout<<endl;
//        for(int i:v) cout<<s[i]<<endl;
            string ans=s[v[0]];
            for(int i=1;i<n;i++){
                ans=f(ans,s[v[i]]);
            }
            mn=min(mn,ans.length());
        }
        while(next_permutation(v.begin(),v.end()));

        printf("Case %d: %d\n",cs,mn);
    }

    return 0;
}

