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
map<int, pair<int,int> > cantor;
void f(){
    int i=1,j=1;
    int cnt=1;
    cantor[1]=mp(1,1);
    while(cnt<=1e7){
        if(i==1){
            cnt++;
            j++;
            //cout<<i<<" "<<j<<" "<<cnt<<endl;
            cantor[cnt]=mp(i,j);
            while(j>1){
                i++;
                j--;
                cnt++;
                //cout<<i<<" "<<j<<" "<<cnt<<endl;
                cantor[cnt]=mp(i,j);
            }
        }
        else if(j==1){
            cnt++;
            i++;
            //cout<<i<<" "<<j<<" "<<cnt<<endl;
            cantor[cnt]=mp(i,j);
            while(i>1){
                i--;
                j++;
                cnt++;
                //cout<<i<<" "<<j<<" "<<cnt<<endl;
                cantor[cnt]=mp(i,j);
            }
        }

    }
}
int main()
{
    f();

    int n;
    bool first=true;
    while(scanf("%d",&n)!=EOF){
        if(!first){
            printf("\n");
        }
        first=false;
        printf("TERM %d IS %d/%d",n,cantor[n].first,cantor[n].second);
    }

    return 0;
}


