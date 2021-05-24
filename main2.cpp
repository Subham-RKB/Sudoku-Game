#include<graphics.h>
int main()
{
    int gd=0,gm;
    initgraph(&gd,&gm,NULL);
    setfillstyle(SOLID_FILL,RED);
    rectangle(50,50,150,150);
    floodfill(51,60,WHITE);
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(150,50,250,150);
    floodfill(151,60,WHITE);
    rectangle(250,50,350,150);
    floodfill(251,60,WHITE);
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(50,150,150,250);
    floodfill(51,160,WHITE);
    rectangle(150,150,250,250);
    floodfill(151,160,WHITE);
    rectangle(250,150,350,250);
    floodfill(251,160,WHITE);
    getch();
    closegraph();
}
