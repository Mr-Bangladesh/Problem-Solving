#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL Square(LL N)
{
    LL a=sqrt(N);
    if(a*a == N)
        return 1;
    else
        return 0;
}
int main()
{
    LL T,N,S,testcase,X,a,s;
    cin>>testcase;
    for(T=1;T<=testcase;T++)
    {
        cin>>N;
        vector <LL> S;
        vector <LL> :: iterator it;
        for(X=1;X<N;X++)
        {
            a=N-X;
            if(Square(a)==1)
            {
                s=sqrt(a);
                if(X%s==0)
                    S.push_back(X);
            }
        }
        printf("Case %lld: ",T);
        for(it=S.begin();it!=S.end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}
