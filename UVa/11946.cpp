#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    string N;
    char A[1007];
    int len;
    int i,j,k;
    int T;
    cin>>T;
    getchar();
    for(int x=1;x<=T;x++)
    {

        getline(cin,N);
        len=N.length();
        j=0;
        for(i=0;i<len;i++)
        {
            if(N[i]=='3')
                A[j]='E';
            else if(N[i]=='0')
                A[j]='O';
            else if(N[i]=='1')
                A[j]='I';
            else if(N[i]=='4')
                A[j]='A';
            else if(N[i]=='9')
                A[j]='P';
            else if(N[i]=='8')
                A[j]='B';
            else if(N[i]=='5')
                A[j]='S';
            else if(N[i]=='7')
                A[j]='T';
            else if(N[i]=='2')
                A[j]='Z';
            else if(N[i]=='6')
                A[j]='G';
            else
                A[j]=N[i];
            j++;
        }
        A[j]='\0';
        cout<<A<<endl;
    }
    return 0;
}
