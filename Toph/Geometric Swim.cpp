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

    cin>>t;
    for(cs=1;cs<=t;cs++){
    	double A,W,S,L;
    	scanf("%lf %lf %lf %lf",&A,&W,&S,&L);
    	/*double t1=(PI*L)/A;
    	double t2=(PI*L)/W;
    	double v=(S/(t1+t2));*/
        double d=abs(A-W);
        double t1=(sqrt(W*W+S*d)-W)/(2*W);
        double t2=(sqrt(A*A+S*d)-A)/(2*A);
        cout<<t1<<" "<<t2<<endl;
        double v=(S/(t1+t2));
    	printf("Case %lld: %.6f\n",cs,v);
    }

    return 0;
}