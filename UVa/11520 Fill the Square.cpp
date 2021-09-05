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

int main()
{
    int t,n;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        scanf("%d",&n);
        string s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        //for(int i=0;i<n;i++) cout<<s[i]<<endl;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='.'){
                    char c='A';
                    for( ;c<='Z';c++){
                        bool check=true;
                        for(int k=0;k<4;k++){
                            int x=i+fx4[k]; int y=j+fy4[k];
                            if(x>=0 && x<n && y>=0 && y<n){
                                if(s[x][y]==c){
                                    check=false; break;
                                }
                            }
                        }
                        if(check) break;
                    }
                    s[i][j]=c;

                    //for(int a=0;a<n;a++) cout<<s[a]<<endl; cout<<endl;
                }
            }
        }
        printf("Case %d:\n",cs);
        for(int i=0;i<n;i++) cout<<s[i]<<endl;
    }

    return 0;
}

