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
vector<char> color{'R','G','B','Y','O','V'};
int main()
{
    vector<int> v{0,1,2,3,4,5};
    int t;
    scanf("%d",&t);
    while(t--){
        string a,b;
        int n,m,n1,m1;
        cin>>a; scanf("%d %d",&n,&m);
        cin>>b; scanf("%d %d",&n1,&m1);
        bool check=false;
        do{
            int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
            set<char> a1,b1;
            for(auto x:a) a1.insert(x);
            for(auto x:b) b1.insert(x);
            map<char,int> idx;
            for(auto x:color){
                idx[x]=-1;
            }
            for(int i=0;i<4;i++){
                idx[color[v[i]]]=i;
                if(color[v[i]]==a[i]){
                    cnt1++;
                    a1.erase(a[i]);
                }
                if(color[v[i]]==b[i]){
                    cnt2++;
                    b1.erase(b[i]);
                }
            }
            for(auto x:a1){
                if(idx[x]!=-1) cnt3++;
            }
            for(auto x:b1){
                if(idx[x]!=-1) cnt4++;
            }
            if(cnt1==n && cnt3==m && cnt2==n1 && cnt4==m1){
                check=true; break;
            }
            //for(auto x:v) cout<<color[x]; cout<<" ";
            //cout<<cnt1<<" "<<cnt3<<" "<<cnt2<<" "<<cnt4<<endl;
        }
        while(next_permutation(v.begin(),v.end()));

        if(check) printf("Possible\n");
        else printf("Cheat\n");
    }
    return 0;
}

