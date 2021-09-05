#include <bits/stdc++.h>
using namespace std;

int square(int a,int b,int c,int d)
{
    if(a==b && b==c && c==d)
        return 1;
    else
        return 0;
}

int rectangle(int a,int b,int c,int d)
{
    if(a==c && b==d)
        return 1;
    else
        return 0;
}

int quadrangle(int a,int b,int c,int d)
{

}
int main()
{
	int T,a,b,c,d;
	cin>>T;
	for(int i=1;i<=T;i++)
    {
        cin>>a>>b>>c>>d;
        if(square(a,b,c,d)==1)
            cout<<"square"<<endl;
        else if(rectangle(a,b,c,d)==1)
            cout<<"rectangle"<<endl;
    }
	return 0;
}
