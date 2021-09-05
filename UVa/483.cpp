#include <bits/stdc++.h>
using namespace std;
int main()
{
    string A;
    int len,i,j;
    int k;
    while(getline(cin,A))
    {
        //getchar();
        len=A.length();
        k=-1;
        for(i=0;i<len;i++)
        {
            if(A[i]==32)
            {
                for(j=i-1;j>k;j--)
                    cout<<A[j];

                cout<<" ";
                k=i;
            }
        }
        for(i=len-1;i>k;i--)
            cout<<A[i];
        cout<<endl;
    }
    return 0;
}
