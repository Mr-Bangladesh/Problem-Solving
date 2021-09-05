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
    int idx,slv,pnlty;
    ff(int a,int b,int c){
        idx=a; slv=b; pnlty=c;
    }
};
bool comp(ff a, ff b){
    if(a.slv==b.slv){
        if(a.pnlty==b.pnlty) return a.idx<b.idx;
        return a.pnlty<b.pnlty;
    }
    return a.slv>b.slv;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar(); getchar();
    while(t--){
        string s;
        int penalty[101][10];
        int solved[101]={0},totalpen[101]={0};
        memset(penalty,0,sizeof(penalty));

        while(getline(cin,s)){
            if(s=="") break;
            istringstream input(s);
            string a;
            vector<string> tmp;
            while(input>>a){
                tmp.pb(a);
            }
            int c=stoi(tmp[0]), p=stoi(tmp[1]), tme=stoi(tmp[2]);

            if(tmp[3]=="C"){
                solved[c]++;
                totalpen[c]+=(penalty[c][p]*20+tme);
            }
            else if(tmp[3]=="I"){
                penalty[c][p]++;
            }
            else if(tmp[3]=="E"){
                penalty[c][p]++;
            }
        }
        vector<ff> v;
        for(int i=1;i<=100;i++){
            if(solved[i]){
                v.pb(ff(i,solved[i],totalpen[i]));
            }
        }
        sort(v.begin(),v.end(),comp);

        for(ff x:v){
            printf("%d %d %d\n",x.idx,x.slv,x.pnlty);
        }
    }

    return 0;
}

