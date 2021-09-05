#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL N;
    while(cin>>N)
    {
        LL S=(N/2) + 1;
        LL LE=S*S;
        LL total=(LE*2 - 1) + ((LE-1)*2 - 1) + ((LE-2)*2 - 1);
        cout<<total<<endl;
    }
    return 0;
}
