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
    for(int cs=1;cs<=t;cs++){
        string s;
        cin>>s;
        int sum=0;
        int len=s.length();
        int cnt=0;
        for(int i=0;i<len;i++){
            sum+=(s[i]-48);
            if((s[i]-48)%3==0) cnt++;
        }
        bool first=0;
        for(int i=0;i<len;i++){
            if((s[i]-48)%3){
                if((sum-(s[i]-48))%3==0){
                    first=true; break;
                }
            }
        }
        //cout<<first<<" "<<cnt<<endl;
        if(cnt%2==0){
            if(first){
                printf("Case %d: S\n",cs);
            }
            else{
                printf("Case %d: T\n",cs);
            }
        }
        else{
            if(first){
                printf("Case %d: T\n",cs);
            }
            else{
                printf("Case %d: S\n",cs);
            }
        }
    }

    return 0;
}


