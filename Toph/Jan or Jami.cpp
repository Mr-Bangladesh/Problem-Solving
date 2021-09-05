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

int dp[30];
int f(int n){
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];
    set<int> s;
    for(int i=1;i<=3;i++){
        s.insert(f(n-i));
    }
    int ret=0;
    while(s.find(ret)!=s.end()){
        ret++;
    }
    return dp[n]=ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    f(25);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int> v;
        for(int i=0;i<3;i++){
            int x='Z'-s[i];
            v.pb(f(x));
        }
        int ans=0;
        for(int x:v){
            ans=ans^x;
        }
        if(ans) cout<<"Jan"<<endl;
        else cout<<"Jami"<<endl;
    }

    return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//
//
//int main(){
//   map < string, int > dp;
//   string state = "ZZZ";
//   dp["ZZZ"] = 0;
//
//   for (char i = 'Z'; i >= 'A'; i--) {
//    state[0] = i;
//    for (char j = 'Z'; j >= 'A'; j--) {
//        state[1] = j;
//        for (char k = 'Z'; k >= 'A'; k--) {
//            state[2] = k;
//            if (i == j && j == k && i == 'Z') {
//                continue;
//            }
//            int lose = 0;
//            // last character
//            if (k + 1 <= 'Z') {
//                string nextState = state;
//                nextState[2] = k + 1;
//                if (dp[nextState] == 0) lose = 1;
//            }
//            if (k + 2 <= 'Z') {
//                string nextState = state;
//                nextState[2] = k + 2;
//                if (dp[nextState] == 0) lose = 1;
//            }
//            if (k + 3 <= 'Z') {
//                string nextState = state;
//                nextState[2] = k + 3;
//                if (dp[nextState] == 0) lose = 1;
//            }
//            // mid
//            if (j + 1 <= 'Z') {
//                string nextState = state;
//                nextState[1] = j + 1;
//                if (dp[nextState] == 0) lose = 1;
//            }
//            if (j + 2 <= 'Z') {
//                string nextState = state;
//                nextState[1] = j + 2;
//                 if (dp[nextState] == 0) lose = 1;
//            }
//            if (j + 3 <= 'Z') {
//                string nextState = state;
//                nextState[1] = j + 3;
//                if (dp[nextState] == 0) lose = 1;
//            }
//            // first
//            if (i + 1 <= 'Z') {
//                string nextState = state;
//                nextState[0] = i + 1;
//                 if (dp[nextState] == 0) lose = 1;
//            }
//            if (i + 2 <= 'Z') {
//                string nextState = state;
//                nextState[0] = i + 2;
//                 if (dp[nextState] == 0) lose = 1;
//            }
//            if (i + 3 <= 'Z') {
//                string nextState = state;
//                nextState[0] = i + 3;
//                if (dp[nextState] == 0) lose = 1;
//            }
//
//            if (lose) {
//                dp[state] = 1;
//            } else dp[state] = 0;
//        }
//    }
//   }
//
//   int q;
//   cin >> q;
//
//   while (q--) {
//    string qu;
//    cin >> qu;
//    if (dp[qu]) {
//        cout << "Jan" << endl;
//    } else {
//        cout << "Jami" << endl;
//    }
//   }
//}
