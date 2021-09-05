/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    string s;
    cin>>s;
    stack<ll> st;
    n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(i);
        else{
            if(st.size()==0){
                cout<<"No"<<endl; return 0;
            }
            ll u=st.top();
            st.pop();
            if(s[i]==')'){
                if(s[u]!='('){
                    cout<<"No"<<endl; return 0;
                   }
            }
            else if(s[i]=='}'){
                if(s[u]!='{'){
                    cout<<"No"<<endl; return 0;
                }
            }
            else{
                if(s[u]!='['){
                    cout<<"No"<<endl; return 0;
                }
            }
        }
    }

    if(st.size()){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }

    return 0;
}


