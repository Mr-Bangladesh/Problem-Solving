#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>n;

    ll A[n+3][n+3];

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
	    	char ch;
	    	cin>>ch;
	    	char a=tolower(ch);
	    	A[i][j]=a-96;
	    }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
    	ans=0;
        for(int j=1;j<=n;j++){
            ans+=A[i][j];
        }
        cout<<ans<<endl;
    }
    ans=0;
    for(int i=1;i<=n;i++){
    	ans=0;
        for(int j=1;j<=n;j++){
            ans+=A[j][i];
        }
        cout<<ans<<endl;
    }
    ans=0;
    for(int i=1;i<=n;i++){
    	ans+=A[i][i];
    }
    cout<<ans<<endl;
    ans=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(i+j==n+1) ans+=A[i][j];
    	}
    }
    cout<<ans<<endl;
    ans=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		ans+=A[i][j];
    	}
    }

    cout<<ans<<endl;

    return 0;
}