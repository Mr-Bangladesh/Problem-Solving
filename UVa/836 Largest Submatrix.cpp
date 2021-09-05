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
    //freopen("1.txt","r",stdin);
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        //getchar();
        //getchar();
        string s;
        int n=0,m=1;
        int a[30][30];
        while(getline(cin,s)){
            if(s=="") break;
            //cout<<s<<endl;
            int len=s.length();
            m=len;
            n++;
            for(int j=0;j<len;j++){
                a[n][j+1]=s[j]-48;
            }
        }
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=m;j++) cout<<a[i][j]<<" "; cout<<endl;
//        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i>1) a[i][j]+=a[i-1][j];
                if(j>1) a[i][j]+=a[i][j-1];
                if(i>1 && j>1) a[i][j]-=a[i-1][j-1];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //cout<<"start "<<i<<" "<<j<<endl;
                for(int k=i;k<=n;k++){
                    for(int l=j;l<=m;l++){
                        //cout<<"end "<<k<<" "<<l<<endl;
                        int sum=a[k][l];
                        if(i>1) sum-=a[i-1][l];
                        if(j>1) sum-=a[k][j-1];
                        if(i>1 && j>1) sum+=a[i-1][j-1];
                        int cnt=(k-i+1)*(l-j+1);
                        //cout<<i<<" "<<j<<" "<<k<<" "<<l<<" total "<<cnt<<" ones "<<sum<<endl;
                        if(sum==cnt) ans=max(ans,sum);
                    }
                }
            }
        }
        printf("%d\n",ans);
        if(t) printf("\n");
    }

    return 0;
}

