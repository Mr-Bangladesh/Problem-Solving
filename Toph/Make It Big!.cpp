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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ans=s;
        int len=s.length();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                for(int k=0;k<len;k++){
                    for(int l=k+1;l<len;l++){
                        string tmp=s;
                        swap(tmp[i],tmp[j]);
                        swap(tmp[k],tmp[l]);
                        ans=max(ans,tmp);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

