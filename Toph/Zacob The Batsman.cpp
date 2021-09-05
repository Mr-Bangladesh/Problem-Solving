#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;
    cin>>t;
    while(t--){
    cin>>n;
    if(n%4==0 || n%6==0){
        cout<<"Zacob Zacob!"<<endl;
        continue;
    }
    if(n%2 || n<4){
        cout<<"Sorry Zacob!"<<endl; continue;
    }
    n/=2;
    if(n%2){
        cout<<"Zacob Zacob!"<<endl;
    }
    else{
        cout<<"Sorry Zacob!"<<endl;
    }
    }

    return 0;
}



