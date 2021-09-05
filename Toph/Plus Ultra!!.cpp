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
    vector<int> v{2,3,5,7,11,13,17,19,23};
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<v.size();j++){
                int tot=v[j];

                for(int k=0;k<v.size();k++){
                    int gap=v[k];
                    //cout<<i<<" "<<v[j]<<" "<<v[k]<<endl;
                    int cur=n-i;
                    int x=cur/gap +1;
                    if(x>=tot){
                        //cout<<i<<" "<<gap<<" "<<tot<<" "<<x<<endl;
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}


