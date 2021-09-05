#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,G,L;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>G>>L;
        if(L%G==0)
            cout<<G<<" "<<L<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
