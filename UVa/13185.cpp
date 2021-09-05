#include <iostream>
using namespace std;
typedef long long L;

L divisors(L number)
{
    L sum;
    L divisor[1000];
    divisor[0]=1;
    int j=1;
    for(int i=2;i<=number/2;i++)
    {
        if(number%i==0)
        {
            divisor[j]=i;
            j++;
        }
    }
    sum=0;
    for(int i=0;i<j;i++)
    {
        sum=sum+divisor[i];
    }
    return sum;

}
int main()
{
    L sum,t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        sum=divisors(n);
        //cout<<"sum "<<sum<<endl;
        if(n==sum)
            cout<<"perfect"<<endl;
        else if(n>sum)
            cout<<"deficient"<<endl;
        else if(n<sum)
            cout<<"abundant"<<endl;
    }
    return 0;
}
