/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
map<ll,set<ll> > g;
set<ll> s;
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&p);
        if(p==1){
            scanf("%lld",&x);
            if(g[x].size()){
                for(auto it:g[x]){
                    x=it;
                    printf("%c",x+64);
                }
                printf("\n");
            }
            else{
                printf("0\n");
            }
        }
        else if(p==2){
            char c;
            cin>>x>>c;
            g[x].insert(c-64);
            s.insert(x);
        }
        else if(p==3){
            scanf("%lld",&x);
            auto it=s.upper_bound(x);
            if(it==s.end()){
                printf("0\n");
            }
            else{
                printf("%lld\n",*it);
            }
        }
        else{
            scanf("%lld",&x);
            if(x==1){
                printf("0\n");
                continue;
            }
            auto it=s.lower_bound(x);
            if(it!=s.begin()){
                it--;
                printf("%lld\n",*it);
            }
            else{
                printf("0\n");
            }
        }
    }

    return 0;
}
