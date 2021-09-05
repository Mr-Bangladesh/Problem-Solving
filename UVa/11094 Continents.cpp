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
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
int n,m,a,b;
string s[30];
bool mark[30][30];
int cnt=0;
char land;
void dfs(int u1,int u2){
    //cout<<u1<<" "<<u2<<endl;
    mark[u1][u2]=1;
    cnt++;
    for(int i=0;i<4;i++){
        int v1=u1+fx4[i]; int v2=u2+fy4[i];
        if(v1==u1 && v2==m){
            v2=0;
        }
        if(v1==u1 && v2==-1){
            v2=m-1;
        }
        if(v1>=0 && v1<n && v2>=0 && v2<m && s[v1][v2]==land && mark[v1][v2]==0){
            dfs(v1,v2);
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        scanf("%d %d",&a,&b);
        land=s[a][b];
        dfs(a,b);
        //cout<<cnt<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]!=land || (i==a && j==b) || mark[i][j]==1){
                    continue;
                }
                cnt=0;
                dfs(i,j);
                ans=max(ans,cnt);
            }
        }
        printf("%d\n",ans);
        memset(mark,0,sizeof(mark));
        cnt=0;
    }

    return 0;
}


