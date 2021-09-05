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
        string s[3];
        for(int i=0;i<3;i++) cin>>s[i];

        //for(int i=0;i<3;i++) cout<<s[i]<<endl;

        int res=-1;
        while(1){
            bool check=false;

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(s[i][j]=='1'){
                        check=true; break;
                    }
                }
            }
            if(!check) break;
            res++;
            string a[3];
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int sum=0;
                    for(int k=0;k<4;k++){
                        int u=i+fx4[k];
                        int v=j+fy4[k];
                        if(u>=0 && v>=0 && u<3 && v<3){
                            if(s[u][v]=='1') sum++;
                        }
                    }
                    sum=sum%2;
                    a[i]+=(sum+48);
                }
            }

            for(int i=0;i<3;i++) s[i]=a[i];
            //cout<<"each step"<<endl;
//            for(int i=0;i<3;i++){
//                cout<<a[i]<<endl;
//            }
        }
        printf("%d\n",res);
    }

    return 0;
}

