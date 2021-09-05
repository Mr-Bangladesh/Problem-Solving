#include <bits/stdc++.h>
using namespace std;

int days(string day);
int months(string month);

int main()
{

    int T;

    int G,D,N;
    int daynumber,monthdays,sum,M;
    string MTH,DAY;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>MTH>>DAY;
        daynumber=days(DAY);
        monthdays=months(MTH);
        G=8-daynumber;
        if(G<2)
            N=1;
        else if(G>=2)
            N=2;
        D=monthdays-G;
        M=D/7;
        sum=M*2 + N;
        if(D%7==6)
            sum++;

        cout<<sum<<endl;
    }
}

int days(string day)
{
    if(day=="SUN")
        return 1;
    else if(day=="MON")
        return 2;
    else if(day=="TUE")
        return 3;
    else if(day=="WED")
        return 4;
    else if(day=="THU")
        return 5;
    else if(day=="FRI")
        return 6;
    else if(day=="SAT")
        return 7;
}

int months(string month)
{
    if(month=="JAN" || month=="MAR" || month=="MAY" || month=="JUL" || month=="AUG" || month=="OCT" || month=="DEC")
        return 31;
    else if(month=="FEB")
        return 28;
    else
        return 30;
}
