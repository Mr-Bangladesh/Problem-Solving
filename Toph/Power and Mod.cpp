/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll add(ll a,ll b,ll m)
{
    ll x=m-a;
    if(x<=b)
        return b-x;
    else
        return a+b;
}
ll mulmod(ll a,ll b,ll m)
{
    ll res=0;
    while(b)
    {
        if(b&1)
            res=add(res,a,m);
        b/=2;
        a=add(a,a,m);
    }
    return res;
}
ll bigmod(ll B,ll P,ll M){
    if(P==0) return 1;
    else if(P%2==0){
        ll R=bigmod(B,P/2,M);
        ll x=mulmod(R%M,R%M,M)%M;
        return x;
    }
    else{
        ll R=bigmod(B,P-1,M);
        ll x=mulmod(R%M,B%M,M)%M;
        return x;
    }
}
ll conv(string s)
{
    ll res=0;
    for(ll i=0; i<s.size(); i++)
    {
        res*=10;
        res+=(ll)s[i]-'0';
    }
    return res;
}
ll f(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res=res*a;
        b/=2;
        a=a*a;
    }
    return res;
}
int main()
{
    ll t,n,m,x,y,w,k,q,r,p,cs;

    cin>>t;
    while(t--){
        string s;
        cin>>x>>y;
        cin>>s;
        m=conv(s);
        if(m){
            cout<<bigmod(x,y,m)<<endl;
        }
        else{
            cout<<f(x,y)<<endl;
        }
    }

    return 0;
}
