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
int row[8];
bool check(int r,int c){
    for(int i=0;i<c;i++){
        if(row[i]==r || (abs(row[i]-r)==abs(i-c))) return false;
    }
    return true;
}
vector< vector<int> > ans;
void backtrack(int c){
    if(c==8){
        //for(int i=0;i<8;i++) cout<<row[i]+1<<" "; cout<<endl;
        vector<int> tmp;
        for(int i=0;i<8;i++){
            tmp.pb(row[i]+1);
        }
        ans.pb(tmp);
        return;
    }
    for(int r=0;r<8;r++){
        if(check(r,c)){
            row[c]=r;
            backtrack(c+1);
        }
    }
}
int main()
{
    backtrack(0);
    int a,b,c,d,e,f,g,h,cs=1;
    while(scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h)!=EOF){
        vector<int> v={a,b,c,d,e,f,g,h};
        int res=INT_MAX;
        for(auto it:ans){
            int cnt=0;
            int i=0;
            for(auto it1:it){
                cnt+=(abs(v[i]-it1)!=0?1:0);
                i++;
            }
            //for(auto it1:it) cout<<it1<<" "; cout<<"  "<<cnt<<endl;
            res=min(res,cnt);
        }
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
