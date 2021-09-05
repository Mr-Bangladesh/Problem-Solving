///***Bismillahir Rahmanir Rahim***
///***Faizul***CSE**4th batch**BU
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
///cin.ignore();
void FastIO()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}
int main()
{
    FastIO();

    int N,Q;

    int test=1;

    while(cin>>N>>Q)
    {
        int A[20000];

        if(N==0 && Q==0) break;

        for(int i=0;i<N;i++) cin>>A[i];

        sort(A,A+N);

        printf("CASE# %d:\n",test++);

        int Key;

        for(int i=0;i<Q;i++)
        {
            cin>>Key;
            bool C=binary_search(A,A+N,Key);

            if(C==false) printf("%d not found\n",Key);
            else
            {
                int pos=lower_bound(A,A+N,Key)-A + 1;

                printf("%d found at %d\n",Key,pos);
            }
        }


    }


    return 0;
}
