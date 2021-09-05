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
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        string s;
        scanf("%d",&n);
        map<string,string> par;
        vector<pair<string,int> > v;
        for(int i=1;i<=n;i++){
            cin>>s; scanf("%d %d",&m,&k);
            v.pb(mp(s,k));
            for(int j=1;j<=m;j++){
                string a;
                cin>>a;
                par[a]=s;
                a+='.';
                par[a]=s;
            }
        }
        map<string,int> cnt;

        getchar();
        while(getline(cin,s)){
            if(s=="") break;
            istringstream input(s);
            string a;
            set<string> tmp;
            while(input>>a){
                tmp.insert(a); //cout<<"word "<<a<<endl;
            }
            for(auto it:tmp){
                if(par[it]!=""){
                    cnt[par[it]]++; //cout<<it<<" "<<par[it]<<endl;
                }
            }
        }
        vector<string> ans;
        for(auto it:v){
            //cout<<it.first<<" "<<cnt[it.first]<<endl;
            if(cnt[it.first]>=it.second){
                ans.pb(it.first);
            }
        }
        if(ans.size()==0){
            printf("SQF Problem.\n");
        }
        else{
            for(int i=0;i<ans.size();i++){
                cout<<ans[i];
                if(i<ans.size()-1){
                    printf(", ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}

