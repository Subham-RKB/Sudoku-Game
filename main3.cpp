/*#include<graphics.h>
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
    int x=50;
    int y=50;
    char ch;
    while(1){
    	cleardevice();
    	if(kbhit()){
    		ch=getch();
    	if(ch==63){
    		setfillstyle(SOLID_FILL,RED);
    		x=100;
    		rectangle(x,y,x+100,y+100);
    		setfillstyle(SOLID_FILL,RED);
    		x+=100;
    		rectangle(x,y,x+100,y+100);
		}
		else if (ch==61){
    		setfillstyle(SOLID_FILL,RED);
    		x-=100;
    		rectangle(x,y,x-100,y);
		}
		else if(ch==62){
    		setfillstyle(SOLID_FILL,RED);
    		y+=100;
    		rectangle(x,y,x,y+100);
		}
		else if(ch==57){
			setfillstyle(SOLID_FILL,RED);
    		y-=100;
    		rectangle(x,y,x,y-100);
			
		}
		if(ch==27){
			exit(0);
		}

		delay(10);
	}
    closegraph();
}
}
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
    int x=50;
    int y=50;
    char ch;
    while(1){
    	//cleardevice();
        ch=getch();
    	if(ch=='6'){
    		setfillstyle(SOLID_FILL,BLUE);
    		x=100;
    		rectangle(150,50,250,150);
    		floodfill(151,160,WHITE);
    		setfillstyle(SOLID_FILL,RED);
    		x+=100;
    		rectangle(x,y,x+100,y);
		}
		else if (ch=='5'){
    		setfillstyle(SOLID_FILL,RED);
    		x-=100;
    		rectangle(x,y,x-100,y);
		}
		else if(ch=='4'){
    		setfillstyle(SOLID_FILL,RED);
    		y+=100;
    		rectangle(x,y,x,y+100);
		}
		else if(ch=='3'){
			setfillstyle(SOLID_FILL,RED);
    		y-=100;
    		rectangle(x,y,x,y-100);
		}
		else if(ch=='2'){
			exit(0);
		}
		else
        {
          break;
        }
		//delay(10);
}
 closegraph();
}
*/
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
    int x1 = 50;
    int y1 = 50;
    int x2 = 150;
    int y2 = 150;
    char ch;
    while(1){
    	//cleardevice();
        ch=getch();
    	if(ch=='d'){
    		setfillstyle(SOLID_FILL,BLUE);
    		rectangle(x1,y1,x2,y2);
    		floodfill(x1+1,y1+1,WHITE);
    		setfillstyle(SOLID_FILL,RED);
    		x1+=100;
    		x2+=100;
    		rectangle(x1,y1,x2,y2);
    		floodfill(x1+1,y1+1,WHITE);
		}
		else if (ch=='5'){
    		setfillstyle(SOLID_FILL,RED);
    		x1-=100;
    		//rectangle(x,y,x-100,y);
		}
		else if(ch=='4'){
    		setfillstyle(SOLID_FILL,RED);
    		y1+=100;
    		//rectangle(x,y,x,y+100);
		}
		else if(ch=='3'){
			setfillstyle(SOLID_FILL,RED);
    		y1-=100;
    		//rectangle(x,y,x,y-100);
		}
		else if(ch=='2'){
			exit(0);
		}
		else
        {
          break;
        }
		//delay(10);
}
 closegraph();
}

