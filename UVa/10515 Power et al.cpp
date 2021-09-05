//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//    string A,B;
//    freopen("1.txt","r",stdin);
//    freopen("2.txt","w",stdout);
//    while(cin>>A>>B)
//    {
//        if(A=="0" && B=="0") break;
//
//        int M=A[A.length()-1]-48;
//        int N=B[B.length()-1]-48;
//        int sum=1;
//        for(int i=1;i<=N;i++)
//        {
//            sum=(sum*M)%10;
//        }
//
//        cout<<sum%10<<endl;
//
//    }
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string A,B;
    while(cin>>A>>B)
    {
        if(A=="0" && B=="0") break;

        if(B=="0"){cout<<1<<endl; continue;}

        string B1="0";

        B1+=B;

        //cout<<A1<<" "<<B1<<endl;

        int len1=B1.length();

        string S;

        S+=B1[len1-2];
        S+=B1[len1-1];

        int len=(S[0]-48)*10 + (S[1]-48);
        int ekok=A[A.length()-1] - 48;

        int mod=len%4;

        if(mod==0) mod=4;
        //cout<<mod<<" "<<ekok<<endl;

        int result=pow(ekok,mod);
        cout<<result%10<<endl;

    }
    return 0;
}
