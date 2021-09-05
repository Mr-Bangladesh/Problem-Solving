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
string add(string a,string b)
{
    int len1=a.length();
    int len2=b.length();
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string one;
    string two;
    if(len1==len2)
    {
        one=a;
        two=b;
    }
    else if(len1>len2)
    {
        for(int i=len2;i<len1;i++)
            b+="0";
        one=a;
        two=b;
    }
    else if(len1<len2)
    {
        for(int i=len1;i<len2;i++)
            a+="0";
        one=a;
        two=b;
    }

    int len=one.length();

    int S,rem,carry;
    string summation;
    carry=0;
    for(int i=0;i<len;i++)
    {
        S=(one[i] - 48) + (two[i] - 48) + carry;
        rem=S%10;
        summation+=(rem + 48);
        if(S<10)
            carry=0;
        else if(S>=10)
            carry=1;
    }
    if(carry==1)
        summation+="1";
    reverse(summation.begin(),summation.end());
    return summation;
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    for(cs=1;cs<=t;cs++){
        string a,b;
        cin>>a>>b;
        cout<<"Case #"<<cs<<": "<<add(a,b)<<endl;
    }

    return 0;
}

