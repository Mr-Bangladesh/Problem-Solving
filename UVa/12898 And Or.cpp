        ///Faizul
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100000

ll B_and(ll A,ll B)
{
    ll sum=A;
    for(ll i=1;i<B;i++)
    {
        sum+=(A+i);
    }
    return sum|B;
}


int main()
{
    ll T,A,B;

    scanf("%lld",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%lld %lld",&A,&B);

        cout<<B_and(A,B)<<endl;

    }


    return 0;
}
