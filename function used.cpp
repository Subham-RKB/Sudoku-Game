#include<stdio.h>
#include<graphics.h>
makeblue(int c,int d,int*x1,int*y1,int*x2,int*y2)
{
    *x1 = c;
    *y1 = d;
    *x2 = *x1 + 60;
    *y2 = *y1 + 60;
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(*x1,*y1,*x2,*y2);
    floodfill(*x1+1,*y1+1,WHITE);
}
makered(int x1,int y1,int x2,int y2)
{
    setfillstyle(SOLID_FILL,RED);
    rectangle(x1,y1,x2,y2);
    floodfill(x1+1,y1+1,WHITE);
}
int main()
{
    int gd = DETECT,gm;
    //initgraph(&gd,&gm,NULL);
    initwindow(1000,750);
    int x1,y1,x2,y2,a,b,c,d;
    int i,j;
    x1 = 150;
    y1 = 100;
    a = x1;
    b = y1;
    c = x1;
    d = y1;
    for(i=1;i<10;i++)
    {
        x1 = a;
        for(j=1;j<10;j++)
        {
            x2 = x1 + 60;
            y2 = y1 + 60;
            setfillstyle(SOLID_FILL,BLUE);
            rectangle(x1,y1,x2,y2);
            floodfill(x1+1,y1+1,WHITE);
            x1+=60;
        }
        y1+=60;

    }
    setfillstyle(SOLID_FILL,RED);
    rectangle(a,b,a+60,b+60);
    floodfill(a+1,b+1,WHITE);
    char ch;
    do
    {
        ch = getch();
        while(ch=='d'||ch=='a'||ch=='w'||ch=='s')
        {
            if(ch=='d')
            {
                if(c!=630)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1+=60;
                    x2+=60;
                    makered(x1,y1,x2,y2);
                    c+=60;
                    /*char ch1;
                    ch1 = getch();
                    char ch2[2];
                    ch2[0] = ch1;
                    ch2[1]='\0';
                    settextstyle(8,0,8);
                    outtextxy(x1,y1,ch2);
                    */
                }
                else if(d!=580)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = a;
                    y1 = d + 60;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    makered(x1,y1,x2,y2);
                    c = a;
                    d+=60;
                }
            }
             if(ch=='a')
            {
                if(c!=a)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1-=60;
                    x2-=60;
                    makered(x1,y1,x2,y2);
                    c-=60;
                }
                else if(d!=b)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = 630;
                    y1 = d - 60;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    makered(x1,y1,x2,y2);
                    c = 630;
                    d-=60;
                }
            }
            if(ch=='s')
            {
                if(d!=580)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    y1+=60;
                    y2+=60;
                    makered(x1,y1,x2,y2);
                    d+=60;
                }
                else if(c!=630)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = c+60;
                    y1 = b;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    makered(x1,y1,x2,y2);
                    c+=60;
                    d = b;
                }
            }
            if(ch=='w')
            {
                if(d!=b)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    y1-=60;
                    y2-=60;
                    makered(x1,y1,x2,y2);
                    d-=60;
                }
                else if(c!=a)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = c-60;
                    y1 = 580;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    makered(x1,y1,x2,y2);
                    c-=60;
                    d = 580;
                }
            }
            ch = getch();
        }
    }while(ch!=' ');

    getch();
    closegraph();
}
