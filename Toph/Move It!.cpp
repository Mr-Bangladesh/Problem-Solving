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
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++) cin>>s[i];
        int w[n+2][n+2],cnt[n+2][n+2];
        memset(w,0,sizeof(w));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<=n;i++){
            if(i>0 && s[0][i-1]=='r') break;
            w[0][i]=1;
            //cout<<1<<" "<<i<<endl;
        }
        for(int i=0;i<=n;i++){
            if(i>0 && s[i-1][0]=='r') break;
            w[i][0]=1;
            //cout<<i<<"  "<<1<<endl;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<w[i][j]<<" "; cout<<endl;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1][j-1]!='r'){
                    w[i][j]=w[i][j-1]+w[i-1][j];
                    cnt[i][j]=max(cnt[i-1][j],cnt[i][j-1])+ (s[i-1][j-1]=='f');
                   // cout<<i<<" "<<j<<" "<<w[i][j]<<endl;
                }

                //cout<<i<<" "<<j<<" "<<w[i][j]<<endl;
            }
        }
        cout<<cnt[n][n]<<" "<<w[n][n]<<endl;
    }

    return 0;
}


