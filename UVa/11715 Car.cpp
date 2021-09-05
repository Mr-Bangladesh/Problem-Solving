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
    int n; double a,b,c;
    int cs=1;
    while(scanf("%d",&n),n){
        scanf("%lf %lf %lf",&a,&b,&c);
        if(n==1){
            double x=(b-a)/c;
            double s=a*c+(x*c*c)/2.0;
            printf("Case %d: %.3f %.3f\n",cs++,s,x);
        }
        else if(n==2){
            double t=(b-a)/c;
            double s=a*t + (c*t*t)/2.0;
            printf("Case %d: %.3f %.3f\n",cs++,s,t);
        }
        else if(n==3){
            double v=sqrt(a*a+2.0*b*c);
            double t=(v-a)/b;
            printf("Case %d: %.3f %.3f\n",cs++,v,t);
        }
        else{
            double u=sqrt(a*a-2.0*b*c);
            double t=(a-u)/b;
            printf("Case %d: %.3f %.3f\n",cs++,u,t);
        }
    }

    return 0;
}


