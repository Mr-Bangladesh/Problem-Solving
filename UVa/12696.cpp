#include <bits/stdc++.h>
using namespace std;

bool baggage(double L,double W, double D,double We)
{
    double sum=L+W+D;
    if(We>7.00)
        return false;
    if( (L>56.00 || W>45.00 || D>25.00) && sum<=125.00)
        return true;
    if(L<=56.00 && D<=45.00 && D<=25.00)
        return true;
    else if(sum>125.00 && (L>56.00 || W>45.00 || D>25.00))
        return false;
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int t;
    double length,width,depth,weight;
    bool check;
    cin>>t;
    int C=0;
    for(int i=1;i<=t;i++)
    {
        cin>>length>>width>>depth>>weight;

        check=baggage(length,width,depth,weight);

        if(check==true)
        {
            cout<<"1"<<endl;
            C++;
        }
        else
            cout<<"0"<<endl;

    }
    cout<<C<<endl;

    return 0;
}
