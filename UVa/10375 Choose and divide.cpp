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

vector<int> ncr(int n,int r){
    int nr=n-r;
    int x=max(r,n-r);
    int y=min(r,n-r);
    vector<int> v,w;
    for(int i=x+1;i<=n;i++) v.pb(i);
    queue<int> q;
    for(int i=1;i<=y;i++){
        q.push(i);
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0;i<v.size();i++){
            int g=__gcd(u,v[i]);
            u/=g;
            v[i]/=g;
        }
        if(u!=1){
            q.push(u);
        }
    }
    for(int x:v){
        if(x!=1) w.pb(x);
    }
    return w;
}

int main()
{
    int a,b,c,d;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF){
        vector<int> x=ncr(a,b);
        vector<int> y=ncr(c,d);
        //for(int i:x) cout<<i<<" "; cout<<endl;
        //for(int j:y) cout<<j<<" "; cout<<endl;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        for(int i=0;i<x.size();i++){
            for(int j=0;j<y.size();j++){
                int g=__gcd(x[i],y[j]);
                x[i]/=g;
                y[j]/=g;
            }
        }
        double lob=1.00,hor=1.00;
        for(int i:x){
            lob*=double(i);
        }
        for(int i:y){
            hor*=double(i);
        }
        printf("%.5f\n",lob/hor);
    }

    return 0;
}


