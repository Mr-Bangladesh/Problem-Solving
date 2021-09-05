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

int f(string text,string pattern){
    int n=text.length();int m=pattern.length();
    if(n<m) return 0;
    int ans=0;
    for(int i=0;i<=n-m;i++){
        int cnt=0;
        for(int j=i;j<i+m;j++){
            //cout<<"start "<<i<<" end "<<i+m-1<<" "<<text[j]<<" "<<pattern[j-i]<<endl;
            if(text[j]==pattern[j-i]) cnt++;
        }
        ans=max(ans,cnt);
    }
    return ans;
}
int main()
{
    //cout<<f("1111100000","110")<<endl;
    int n,q;
    scanf("%d %d",&n,&q);
    vector<string> v;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        v.pb(s);
    }
    while(q--){
        cin>>s;
        int mx=0,idx=1;
        for(int i=0;i<n;i++){
            int cnt=f(v[i],s);
            //cout<<i+1<<" "<<v[i]<<" "<<s<<" "<<cnt<<endl;
            if(cnt>mx){
                mx=cnt;
                idx=i+1;
            }
        }
        printf("%d\n",idx);
    }

    return 0;
}

