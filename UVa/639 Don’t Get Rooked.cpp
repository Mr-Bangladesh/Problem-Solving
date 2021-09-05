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
    int n;
    while(scanf("%d",&n),n){
        string s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int ans=0;
        for(int mask=0;mask<(1<<(n*n));mask++){
            int mask1=mask;
            for(int i=0;i<n*n;i++){
                if((mask1&(1<<i))){
                    int x=i/n; int y=i%n;
                    //cout<<mask<<" "<<mask1<<" "<<i<<" th bit on "<<x<<" "<<y<<" char "<<s[x][y]<<endl;
                    if(s[x][y]=='X'){
                        mask1^=(1<<i);
                        continue;
                    }
                    //left
                    for(int c=y-1;c>=0;c--){
                        if(s[x][c]=='X') break;
                        int idx=n*x+c;
                        if(mask1&(1<<idx)){
                            mask1=mask1^(1<<idx);
                        }
                    }
                    for(int c=y+1;c<n;c++){
                        if(s[x][c]=='X') break;
                        int idx=n*x+c;
                        if(mask1&(1<<idx)){
                            mask1=mask1^(1<<idx);
                        }
                    }
                    for(int r=x-1;r>=0;r--){
                        if(s[r][y]=='X') break;
                        int idx=n*r+y;
                        if(mask1&(1<<idx)){
                            mask1=mask1^(1<<idx);
                        }
                    }
                    for(int r=x+1;r<n;r++){
                        if(s[r][y]=='X') break;
                        int idx=n*r+y;
                        if(mask1&(1<<idx)){
                            mask1=mask1^(1<<idx);
                        }
                    }
                }
            }
            int cnt=0;
            for(int i=0;i<n*n;i++){
                if(mask1&(1<<i)){
                    cnt++;
                }
            }
            //cout<<mask<<" "<<mask1<<" "<<cnt<<endl;
            ans=max(ans,cnt);
        }
        printf("%d\n",ans);
    }

    return 0;
}

