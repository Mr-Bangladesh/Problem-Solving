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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
string s[3];
bool checkrow(char c){
    for(int i=0;i<3;i++){
        if(s[i][0]==c && s[i][1]==c && s[i][2]==c){
            return true;
        }
    }
    return false;
}
bool checkcol(char c){
    for(int i=0;i<3;i++){
        if(s[0][i]==c && s[1][i]==c && s[2][i]==c){
            return true;
        }
    }
    return false;
}
bool checkdiag(char c){
    if(s[0][0]==c && s[1][1]==c && s[2][2]==c) return true;
    if(s[0][2]==c && s[1][1]==c && s[2][0]==c) return true;
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<3;i++){
            cin>>s[i];
        }
        int cntx=0,cnto=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(s[i][j]=='X') cntx++;
                else if(s[i][j]=='O') cnto++;
            }
        }
        bool check=true;
        if(cnto>cntx){
            check=false;
        }
        if(cntx-cnto>1){
            check=false;
        }
        bool x=checkrow('X')||checkcol('X')||checkdiag('X');
        if(x){
            if(cntx-cnto!=1){
                check=false;
            }
        }
        bool y=checkrow('O')||checkcol('O')||checkdiag('O');
        if(y){
            if(cntx-cnto!=0){
                check=false;
            }
        }
        if(x && y){
            check=false;
        }
        if(check){
            printf("yes");
        }
        else{
            printf("no");
        }
        if(t) printf("\n");
    }

    return 0;
}


