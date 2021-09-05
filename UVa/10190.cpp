#include <bits/stdc++.h>
using namespace std;

typedef long long ULL;

int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    ULL n,m,i,j,k;
    //ULL A[200000];
    while(cin>>n>>m)
    {
        if ( n < 2 || m < 2 || m > n ){
            cout<<"Boring!"<<endl;
            continue;}

        vector <ULL> A;
        bool check=false;
        while(n>1)
        {
            if(n%m==0)
                A.push_back(n);
            else
                check=true;
            n=n/m;

        }
        A.push_back(1);

        if(check==true)
            cout<<"Boring!"<<endl;
        else{
            j=1;
            for(i=0;i<A.size();i++)
            {
                cout<<A[i];
                if(j<A.size())
                    cout<<" ";
                j++;
            }
            cout<<endl;
        }
    }
    return 0;
}
