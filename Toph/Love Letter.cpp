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

bool cmp(string a, string b){
    return a.length()<b.length();
}
int main()
{
    int n,m;
    cin>>n>>m;
    string s;
    vector< string > v;
    cin.ignore();
    for(int i=1;i<=2*n;i++){
        string a;
        getline(cin,a);
        string b="";
        int len=a.length();
        for(int j=0;j<len;j++){
            if(a[j]!=' ') b+=a[j];
        }
        //cout<<a<<" "<<len<<endl;
        //cout<<a<<" "<<b<<endl;
        v.pb(b);
    }

    sort(v.begin(),v.end(),cmp);
    set<int> x;
    for(int i=0;i<2*n;i++) x.insert(i);

    int row=0;
    bool check=true;
    bool mark[2*n+2]={0};
    for(int i=0;i<2*n;i++){
        if(mark[i]) continue;
        int len=v[i].length();
        if(len>m){
            check=false; break;
        }

        int baki=m-len;
        int mn=INT_MAX,idx=-1;
        for(int j=i+1;j<2*n;j++){
            if(mark[j]) continue;
            if(v[j].length()<=baki){
                if(baki-v[j].length()<mn){
                    mn=baki-v[j].length();
                    idx=j;
                }
            }
        }
        if(idx!=-1){
            mark[idx]=1;
        }
        //cout<<i<<" "<<idx<<" "<<row<<endl;
        row++;

        if(row>n){
            check=false; break;
        }
    }
    //cout<<check<<" "<<row<<endl;
    if(!check){
        cout<<"NO"<<endl; return 0;
    }

    cout<<"YES"<<endl;

    return 0;
}


