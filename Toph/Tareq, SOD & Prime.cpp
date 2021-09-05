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

#define MAX 100000001
vector<int> Primes;
int least[MAX];
void linearsieve(){
    for(int i=2;i<MAX;i++){
        if(!least[i]){
            least[i]=i;
            Primes.pb(i);
        }
        for(int x:Primes){
            if(x>least[i] | i*x>=MAX) break;
            least[i*x]=x;
        }
    }
}

const int lim=1000001;
int sod[lim],ssod[lim];

void init(){
    for(int i=1;i<lim;i++){
        sod[i]=1;
        ssod[i]=1;
    }
    for(int i=2;i<lim;i++){
        for(int j=i;j<lim;j+=i){
            sod[j]+=i;
            ssod[j]+=sod[i];
        }
    }
}

int main()
{
    linearsieve();
    init();
//    int a=0,b=0,c;
//    for(int i=1;i<lim;i++){
//        if(ssod[i]>b){
//            b=ssod[i];
//            a=i;
//            c=sod[i];
//        }
//    }
//    cout<<a<<" "<<b<<" "<<c<<endl;

    //cout<<sod[6]<<" "<<ssod[6]<<endl;

    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        int x,y;
        x=ssod[n]; y=sod[n];
        int i=upper_bound(Primes.begin(),Primes.end(),x)-Primes.begin();
        int j=lower_bound(Primes.begin(),Primes.end(),y)-Primes.begin();
        printf("Case %d: %d\n",cs++,i-j);
    }

    return 0;
}


