#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,0}; ll fy4[]={0,1};

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;

    for(cs=1;cs<=t;cs++){
        cin>>n>>m;
        char s[n+4][m+4];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cin>>s[i][j];
        }

        string a="abcdefghijklmnopqrstuvwxyz";
        set<string> ans;

        for(char ch:a){
            x=0,y=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i][j]==ch){
                        x=i; y=j;
                        char mn='z'; bool check=false;
                        for(int i1=0;i1<2;i1++){
                            ll u=fx4[i1]+x; ll v=fy4[i1]+y;
                            if(u>=1 && v>=1 && u<=n && v<=m && s[u][v]!='X'){
                                mn=min(mn,s[u][v]);
                                check=true;
                            }
                        }

                        if(check){
                            string a; a+=ch; a+=mn;
                            cout<<ch<<" "<<mn<<" "<<a<<endl;
                            ans.insert(a);
                        }
                    }
                }
            }
        }
        for(auto i:ans) cout<<i<<endl;
    }

    return 0;
}



