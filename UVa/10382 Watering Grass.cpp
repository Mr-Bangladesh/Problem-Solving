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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    int n,l,w;
    while(scanf("%d %d %d",&n,&l,&w)!=EOF){
        vector< pair<double,double> > v;
        for(int i=1;i<=n;i++){
            int x,r;
            scanf("%d %d",&x,&r);
            double h2=(double)4*r*r-(double)w*w;
            if(h2>=0){
                double h=sqrt(h2)/2.00;
                double r1=(double)x-h;
                double r2=(double)x+h;
                v.pb(mp(r1,r2));
            }
        }
        sort(v.begin(),v.end());
        double cur=0.00;
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i].first>cur){
                break;
            }
            //cout<<i+1<<" "<<v[i].first<<" "<<v[i].second<<" "<<cur<<endl;
            double mx=v[i].second;
            int j=i;
            while(j+1<v.size() && v[j+1].first<=cur){
                j++;
                mx=max(mx,v[j].second);
            }
            i=j;
            cur=mx;
            cnt++; //cout<<cur<<" "<<cnt<<endl;
            if(cur>=(double)l) break;
        }
        if(cur<(double)l) cnt=-1;
        printf("%d\n",cnt);
    }

    return 0;
}

