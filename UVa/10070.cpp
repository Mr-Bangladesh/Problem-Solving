#include <bits/stdc++.h>
using namespace std;

bool leapyear(int year)
{
    if(year%4==0)
    {
        if(year%100!=0  && year%400==0)
        {
            return true;
        }


    }
    else
        return false;
}
bool huluculu(int year)
{
    if(year%15==0)
        return 1;
    else
        return 0;
}
bool buluculu(int year)
{

}

int main()
{

}
