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
    int n,m;
    while(scanf("%d %d",&n,&m)){
        if(n==0 && m==0) break;
        set<int> s;
        for(int i=1;i<=n;i++) s.insert(i);
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            auto it1=s.lower_bound(x);
            auto it2=s.upper_bound(y);
            //it2--;
            vector<int> temp;
            while(it1!=it2){
                temp.pb(*it1);
                it1++;
            }
            for(auto k:temp) s.erase(k);
//            cout<<"set ";
//            for(auto xx:s) cout<<xx<<" "; cout<<endl;
//            cout<<x<<"  "<<y<<endl;
                if(s.size()==0){
                    printf("* *\n");
                    continue;
                }

            auto left=s.lower_bound(x); left--;
            auto right=s.upper_bound(y);

            //if(left==s.begin())

            //cout<<*left<<" "<<*right<<endl;

            if((*left>x || *left==0) && *right<y) printf("* *\n");
            else if(*left>x || *left==0) printf("* %d\n",*right);
            else if(*right<y) printf("%d *\n",*left);
            else printf("%d %d\n",*left,*right);
        }
        printf("-\n");
    }

    return 0;
}

