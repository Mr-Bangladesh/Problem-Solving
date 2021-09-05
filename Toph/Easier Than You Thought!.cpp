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
    string a="Programming Club, CSE CoU.";

    map<char,int> cnt;
    for(int i=0;i<a.size();i++){
        cnt[a[i]]++;
    }

    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        int len=s.length();
        map<char,int> res;
        for(int i=0;i<len;i++){
            res[s[i]]++;
        }
        bool check=true;
        for(auto it:cnt){
            if(res[it.first]<it.second){
                check=false; break;
            }
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}


