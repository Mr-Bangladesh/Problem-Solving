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
int fx[]={1,-1,0,0,-1,1,1,-1};
int fy[]={0,0,1,-1,-1,1,-1,1};
int main()
{
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int ans[n][m];
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='*') continue;
            int cnt=0;
            for(int k=0;k<8;k++){
                int x=i+fx[k]; int y=j+fy[k];
                if(x>=0 && x<n && y>=0 && y<m && s[x][y]=='*') cnt++;
            }
            ans[i][j]=cnt;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans[i][j]==0) cout<<s[i][j];
            else cout<<ans[i][j];
        }
        cout<<endl;
    }

    return 0;
}


