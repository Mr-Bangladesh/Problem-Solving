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
bool check(int n){
    if(n%7==0) return true;
    while(n){
        if(n%10==7) return true;
        n/=10;
    }
    return false;
}
int main()
{
    int n,m,k;
    while(scanf("%d %d %d",&n,&m,&k),n||m||k){
        int cnt=0;
        int cur=1,id=0;
        bool up=true;
        while(cnt<k){
            id++;
            //cout<<id<<" "<<cnt<<endl;
            if(cur==m && check(id)){
                cnt++;
            }
            if(up){
                cur++;
                if(cur==n) up=false;
            }
            else{
                cur--;
                if(cur==1) up=true;
            }
        }
        printf("%d\n",id);
    }

    return 0;
}


