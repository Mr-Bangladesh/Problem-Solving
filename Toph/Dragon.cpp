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
        printf("Case %lld: ",cs);
    	cin>>n>>x>>y;
    	ll a[n+5];
    	vector<ll> v;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
    		if(a[i]==0){
    			v.pb(i);
    		}
    	}
    	if(a[n]==1 || a[1]==1){
            printf("Google Can Not!\n");
            continue;
    	}
    	ll pos=1;
    	bool check=true;
    	while(pos<=n){
                if(pos==n){
                    check=true; break;
                }
    			ll idx=upper_bound(v.begin(),v.end(),pos)-v.begin();
                idx=v[idx];
                if(idx-pos==1){
                    pos=idx;
                }
                else if(idx-pos>=x && idx-pos<=y){
                    pos=idx;
                }
                else{
                    check=false; break;
                }
    	}
    	if(check) cout<<"Google Can!"<<endl;
    	else cout<<"Google Can Not!"<<endl;
    }

    return 0;
}