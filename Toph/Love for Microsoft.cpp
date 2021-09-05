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
    string s;
    cin>>s;
    int len=s.length();
    bool check=true;
    map<char,int> cnt;
    for(int i=0;i<len;i++){
        cnt[s[i]]++;

    }

    for(char c:{'m','i','c','r','o','s','f','t'}){
        if(!cnt[c]){
            check=false;
            break;
        }
    }
    if(check){
        cout<<"We both love Microsoft!"<<endl;
    }
    else{
        cout<<"Only I love Microsoft!"<<endl;
    }

    return 0;
}


