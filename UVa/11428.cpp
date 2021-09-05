#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    double N,x,y,i,j,sum;
    while(cin>>N)
    {
        if(N==0)
            break;
        int check=0;
        for(i=1;i<=sqrt(N);i++)
        {
            for(j=0;j<i;j++)
            {
                sum=pow(i,3)-pow(j,3);
                if(sum==N)
                {
                    check=1;
                    x=i;
                    y=j;
                    break;
                }
            }
            if(check==1)
                break;

        }
        if(check==1)
            printf("%.0lf %0.lf\n",x,y);
            //cout<<x<<" "<<y<<endl;
        else
            cout<<"No solution"<<endl;
    }
    return 0;
}
