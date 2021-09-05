#include <bits/stdc++.h>
using namespace std;
int main()
{
    int C,N,grade[10000],i,j,sum,c;
    double avg,result;
    cin>>C;
    for(i=1;i<=C;i++)
    {
        cin>>N;
        sum=0;
        for(j=0;j<N;j++)
        {
            cin>>grade[j];
            sum=sum+grade[j];
        }
        avg=float(sum)/float(N);
        c=0;
        for(j=0;j<N;j++)
        {
            if(grade[j]>avg)
                c++;
        }
        result=(float(c)/float(N))*100;
        printf("%.3lf%%\n",result);
    }
    return 0;
}
