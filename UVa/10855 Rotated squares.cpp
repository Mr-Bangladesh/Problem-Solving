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
        string a[n+2],b[m+2],a90[n+2],a180[n+2],a270[n+2];
        char b90[m+2][m+2],b180[m+2][m+2],b270[m+2][m+2];
        for(int i=0;i<n;i++){
            cin>>a[i];
            a90[i]=a180[i]=a270[i]=a[i];
        }
        for(int i=0;i<m;i++) cin>>b[i];

        int val[m+2];
        int x=m;
        for(int i=0;i<m;i++){
            x--;
            val[i]=x;
        }

        for(int i=0;i<m;i++){
            int y=val[i];
            for(int j=0;j<m;j++){
                b90[j][y]=b[i][j];
            }
        }

        for(int i=0;i<m;i++){
            int y=val[i];
            for(int j=0;j<m;j++){
                b180[j][y]=b90[i][j];
            }
        }

        for(int i=0;i<m;i++){
            int y=val[i];
            for(int j=0;j<m;j++){
                b270[j][y]=b180[i][j];
            }
        }

        int cnt0,cnt90,cnt180,cnt270;
        cnt0=cnt90=cnt180=cnt270=0;

        for(int i=0;i<n-m+1;i++){
            for(int j=0;j<n-m+1;j++){
                int cnt=0;
                for(int k=0;k<m;k++){
                    for(int l=0;l<m;l++){
                        if(a[i+k][j+l]==b[k][l]) cnt++;
                    }
                }
                if(cnt==m*m){
                    cnt0++;
                    for(int k=0;k<m;k++){
                        for(int l=0;l<m;l++){
                            a[i+k][j+l]='X';
                        }
                    }
                }
            }
        }

        for(int i=0;i<n-m+1;i++){
            for(int j=0;j<n-m+1;j++){
                int cnt=0;
                for(int k=0;k<m;k++){
                    for(int l=0;l<m;l++){
                        if(a90[i+k][j+l]==b90[k][l]) cnt++;
                    }
                }
                if(cnt==m*m){
                    cnt90++;
                    for(int k=0;k<m;k++){
                        for(int l=0;l<m;l++){
                            a90[i+k][j+l]='X';
                        }
                    }
                }
            }
        }

        for(int i=0;i<n-m+1;i++){
            for(int j=0;j<n-m+1;j++){
                int cnt=0;
                for(int k=0;k<m;k++){
                    for(int l=0;l<m;l++){
                        if(a180[i+k][j+l]==b180[k][l]) cnt++;
                    }
                }
                if(cnt==m*m){
                    cnt180++;
                    for(int k=0;k<m;k++){
                        for(int l=0;l<m;l++){
                            a180[i+k][j+l]='X';
                        }
                    }
                }
            }
        }

        for(int i=0;i<n-m+1;i++){
            for(int j=0;j<n-m+1;j++){
                int cnt=0;
                for(int k=0;k<m;k++){
                    for(int l=0;l<m;l++){
                        if(a270[i+k][j+l]==b270[k][l]) cnt++;
                    }
                }
                if(cnt==m*m){
                    cnt270++;
                    for(int k=0;k<m;k++){
                        for(int l=0;l<m;l++){
                            a270[i+k][j+l]='X';
                        }
                    }
                }
            }
        }

        printf("%d %d %d %d\n",cnt0,cnt90,cnt180,cnt270);

    }

    return 0;
}

