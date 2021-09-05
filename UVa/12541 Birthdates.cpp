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
struct ff{
    string name; int dd,mm,yyyy;
    ff(string a,int b,int c,int d){
        name=a; dd=b; mm=c; yyyy=d;
    }
};
bool cmp(ff a,ff b){
    if(a.yyyy==b.yyyy){
        if(a.mm==b.mm) return a.dd<b.dd;
        return a.mm<b.mm;
    }
    return a.yyyy<b.yyyy;
}
int main()
{
    int n;
    vector<ff > v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s; int dd,mm,yyyy;
        cin>>s;
        scanf("%d %d %d",&dd,&mm,&yyyy);
        v.pb(ff(s,dd,mm,yyyy));
    }
    sort(v.begin(),v.end(),cmp);

    cout<<v[n-1].name<<endl<<v[0].name<<endl;

    return 0;
}

