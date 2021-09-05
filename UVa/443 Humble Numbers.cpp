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
    ll a[40],b[40],c[40],d[40];
    a[0]=1;
    for(int i=1;i<=31;i++){
        a[i]=a[i-1]*2;
    }
    b[0]=1;
    for(int i=1;i<=20;i++){
        b[i]=b[i-1]*3;
    }
    c[0]=1;
    for(int i=1;i<=14;i++){
        c[i]=c[i-1]*5;
    }
    d[0]=1;
    for(int i=1;i<=12;i++){
        d[i]=d[i-1]*7;
    }
    ll lim=2000000000;
    vector<ll> v;
    v.pb(0);
    for(int i=0;i<=31;i++){
        for(int j=0;j<=20;j++){
            for(int k=0;k<=14;k++){
                for(int l=0;l<=12;l++){
                    ll sum=a[i]*b[j]*c[k]*d[l];
                    if(sum>0) v.pb(sum);
                }
            }
        }
    }
    sort(v.begin(),v.end());

    //for(ll x:v) cout<<x<<endl;

    //cout<<v.size()<<endl;

    ll n;
    while(scanf("%lld",&n),n){
        if(n%10==1 && n%100!=11){
            printf("The %lldst humble number is %lld.\n",n,v[n]);
        }
        else if(n%10==2 && n%100!=12){
            printf("The %lldnd humble number is %lld.\n",n,v[n]);
        }
        else if(n%10==3 && n%100!=13){
            printf("The %lldrd humble number is %lld.\n",n,v[n]);
        }
        else{
            printf("The %lldth humble number is %lld.\n",n,v[n]);
        }
    }

    return 0;
}


