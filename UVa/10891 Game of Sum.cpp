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

pair<int,int> f(int a[],int l,int r){
    int mx=INT_MIN;
    int sum=0,idx=-1;
    for(int i=l;i<=r;i++){
        sum+=a[i];
        if(sum>=mx){
            mx=sum;
            idx=i;
        }
    }
    return mp(mx,idx);
}
pair<int,int> g(int a[],int l,int r){
    int mx=INT_MIN,sum=0,idx=-1;
    for(int i=r;i>=l;i--){
        sum+=a[i];
        if(sum>=mx){
            mx=sum;
            idx=i;
        }
    }
    return mp(mx,idx);
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
        int a[n+1];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int l=1,r=n;
        int first=0,second=0;
        int cnt=0;
        while(l<=r){
            cnt++;
            pair<int,int> x=f(a,l,r);
            pair<int,int> y=g(a,l,r);
            //cout<<l<<" "<<r<<"  "<<x.first<<" "<<x.second<<"  "<<y.first<<" "<<y.second<<" "<<cnt<<endl;
            if(x.first>=y.first){
                l=x.second+1;
                if(cnt%2) first+=x.first;
                else second+=x.first;
            }
            else{
                r=y.second-1;
                if(cnt%2) first+=y.first;
                else second+=y.first;
            }
        }
        //cout<<first<<" "<<second<<endl;
        printf("%d\n",first-second);
    }

    return 0;
}


