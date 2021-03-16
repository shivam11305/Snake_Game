#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

int width =20 ,height=20;
int snake ,food,gameover;
int x,y;
int foodX,foodY,score,flag;
int tailX[100],tailY[100];
int countTail=0;

void setup()
{
    gameover=0;
    x=width/2;
    y=height/2;

    label1:
    foodX=rand()%20;
    if(foodX==0)
        goto label1;

    label2:
    foodY=rand()%20;
    if(foodY==0)
        goto label2;
    score=0;
}
void draw()
{
    int i,j;
    system("cls");
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            if(i==0||i==height-1)
                printf("-");
            else if(j==0||j==width-1)
            {
                printf("|");
            }
            else
            {
                if(i==x&&j==y)
                {
                    printf("O");
                }
                else if(i==foodX && j==foodY)
                {
                    printf("F");
                }
                else
                {
                    int ch,k;
                    for(k=0;k<countTail;k++)
                    {
                        if(i==tailX[k]&&j==tailY[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                        printf(" ");
                }

            }
        }
        printf("\n");
    }
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a' : flag=1;
            break;

            case 's' : flag=2;
            break;

            case 'w' : flag=3;
            break;

            case 'z' : flag=4;
            break;

            case 'x' : gameover=1;
            break;
        }
    }
}
void makeLogic()
{
    int i,prev2X,prev2Y;
    int prevX=tailX[0];
    int prevY=tailY[0];

    tailX[0]=x;
    tailY[0]=y;
    for(i=1;i<countTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }

    if(flag==1)
    {
        y--;
    }
    else if(flag==2)
    {
        y++;
    }
    else if(flag==3)
    {
        x--;
    }
    else if(flag==4)
    {
        x++;
    }
    if(x<0||x>width||y<0||y>height)
    {
        gameover=1;
    }
    if(x==foodX && y==foodY)
    {

    label3:
    foodX=rand()%20;
    if(foodX==0)
        goto label3;

    label4:
    foodY=rand()%20;
    if(foodY==0)
        goto label4;
        score+=10;
        countTail++;
    }
}
int main()
{
    char c;
    label5:
    setup();
    while(!gameover)
    {
        draw();
        input();
        makeLogic();
        printf("your score is=%d",score);
    }
    printf("enter y to continue:");
    scanf("%c",&c);
    if(c=='y'||c=='Y')
    {
        goto label5;
    }
    return 0;
}
