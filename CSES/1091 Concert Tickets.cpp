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

map<int,int> cnt;

int main()
{
    int n,m;
    cin>>n>>m;
    int x;
    set<int> s;
    for(int i=1;i<=n;i++){
        cin>>x;
        s.insert(x);
        cnt[x]++;
    }
    for(int i=1;i<=m;i++){
        cin>>x;
        //for(auto it:s) cout<<(it)<<" "; cout<<endl;
        auto it=s.lower_bound(x);
        if(it==s.end()){
            if(s.size()==0) cout<<-1<<endl;
            else{
                it--;
                cout<<(*it)<<endl;
                if(cnt[*it]==1){
                    s.erase(*it);
                }
                cnt[*it]--;
            }
        }
        else if(*it>x){
            if(it==s.begin()) cout<<-1<<endl;
            else{
                it--;
                cout<<(*it)<<endl;
                if(cnt[*it]==1){
                    s.erase(*it);
                }
                cnt[*it]--;
            }
        }
        else{
            cout<<(*it)<<endl;
            if(cnt[*it]==1){
                s.erase(*it);
            }
            cnt[*it]--;
        }
    }

    return 0;
}


