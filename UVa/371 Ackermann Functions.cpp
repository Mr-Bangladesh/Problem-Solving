#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll length(ll N)
{
    if(N==1) return 3;

    ll Count=0;
    while(N!=1)
    {
        if(N%2==0) N=N/2;
        else N=3*N + 1;
        Count++;
    }
    return Count;
}

int main()
{
    ll L,H,V,S;
    while(scanf("%lld %lld",&L,&H))
    {
        if(L==0 && H==0) break;
        ll lower=L; ll higher=H;
        if(H<L) swap(H,L);

        ll MAX= 0;
        ll num;

        for(ll i=L;i<=H;i++)
        {
            ll result=length(i);
            //cout<<result<<endl;
            if(result>MAX) {MAX = result; num=i;}
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",lower,higher,num,MAX);
    }
    return 0;
}
