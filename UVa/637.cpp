#include <bits/stdc++.h>
using namespace std;

char  blank[]="Blank";

int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int pages,front1,front2,back1,back2;

    while(cin>>pages)
    {
        if(pages==0)
            break;

        float sheet=ceil(float(pages)/4.0);
        int gap=(int(sheet)*4)-pages;

        if(pages%4==0)
        {
            printf("Printing order for %d pages:\n",pages);
            front1=pages;
            front2=1;
            back1=2;
            back2=pages-1;
            for(int i=1;i<=(pages/4);i++)
            {
                printf("Sheet %d, front: %d, %d\n",i,front1,front2);
                printf("Sheet %d, back : %d, %d\n",i,back1,back2);

                front1-=2;
                front2+=2;
                back1+=2;
                back2-=2;
            }
        }

        if(gap==1)
        {
            printf("Printing order for %d pages:\n",pages);
            front1=pages+1;
            front2=1;
            back1=2;
            back2=pages;

            for(int i=1;i<=int(sheet);i++)
            {
                if(i==1)
                {
                    printf("Sheet %d, front: %s, %d\n",i,blank,front2);
                    printf("Sheet %d, back : %d, %d\n",i,back1,back2);
                }
                else
                {
                    printf("Sheet %d, front: %d, %d\n",i,front1,front2);
                    printf("Sheet %d, back : %d, %d\n",i,back1,back2);
                }

                front1-=2;
                front2+=2;
                back1+=2;
                back2-=2;
            }
        }

        else if(gap==2)
        {
            printf("Printing order for %d pages:\n",pages);
            front1=pages+2;
            front2=1;
            back1=2;
            back2=pages+1;

            for(int i=1;i<=int(sheet);i++)
            {
                if(i==1)
                {
                    printf("Sheet %d, front: %s, %d\n",i,blank,front2);
                    printf("Sheet %d, back : %d, %s\n",i,back1,blank);
                }
                else
                {
                    printf("Sheet %d, front: %d, %d\n",i,front1,front2);
                    printf("Sheet %d, back : %d, %d\n",i,back1,back2);
                }

                front1-=2;
                front2+=2;
                back1+=2;
                back2-=2;
            }
        }

        if(gap==3)
        {
            printf("Printing order for %d pages:\n",pages);
            front1=pages+3;
            front2=1;
            back1=2;
            back2=pages+2;

            for(int i=1;i<=int(sheet);i++)
            {
                if(i==1)
                {
                    printf("Sheet %d, front: %s, %d\n",i,blank,front2);
                    if(sheet==1)
                        break;
                    printf("Sheet %d, back : %d, %s\n",i,back1,blank);
                }
                else if(i==2)
                {
                    printf("Sheet %d, front: %s, %d\n",i,blank,front2);
                    printf("Sheet %d, back : %d, %d\n",i,back1,back2);
                }
                else
                {
                    printf("Sheet %d, front: %d, %d\n",i,front1,front2);
                    printf("Sheet %d, back : %d, %d\n",i,back1,back2);
                }

                front1-=2;
                front2+=2;
                back1+=2;
                back2-=2;
            }
        }


    }
    return 0;
}
