#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <stdio.h>  
#define UNASSIGNED 0 
#define N 9 
int greed[N][N];
void solver(int gen[9][9]);
int gen[9][9];
int row(int i,int j,int a[9][9]); 
int col(int i,int j,int a[9][9]);
int box(int i,int j,int a[9][9]);	
void generator(int gen[9][9]);
void solver(int gen[9][9]);
int solve_sudoku();
int is_safe(int n, int r, int c);
int number_unassigned(int *row, int *col);

int starttt=1;
int level=0;
int mainpage=0;
int sudoku[9][9];
void sudokuvalueinput()
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            sudoku[i][j]=0;
        }
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%4d",sudoku[i][j]);
        }
        printf("\n");
    }
}
void makeblue(int c,int d,int*x1,int*y1,int*x2,int*y2)
{
    *x1 = c;
    *y1 = d;
    *x2 = *x1 + 60;
    *y2 = *y1 + 60;
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(*x1,*y1,*x2,*y2);
    floodfill(*x1+1,*y1+1,WHITE);
}

void makegreen(int x1,int y1,int x2,int y2)
{
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(x1,y1,x2,y2);
    floodfill(x1+1,y1+1,WHITE);
}
void makered(int x1,int y1,int x2,int y2)
{
    setfillstyle(SOLID_FILL,RED);
    rectangle(x1,y1,x2,y2);
    floodfill(x1+1,y1+1,WHITE);
}
void inputnumber(int x1,int y1,char ch,int gen[9][9])
{
	int i,j,k;
    char ch1[2];
    ch1[0]=ch;
    ch1[1]='\0';
    j = (x1/60)-2;
    i = (y1/60)-1;
    k = ch - '0';
    if(gen[i][j]==0){
    settextstyle(10,0,5);
    outtextxy(x1+15,y1+5,ch1);
	}
    sudoku[i][j] = k;
}
void check(int gen[9][9],int x1,int y1){
	int t=int(x1/60)-2;
	int tt=int(y1/60)-1;
	int s=t;
	generator(gen);
	while(gen[tt][t]!=0){
		if(s<8){
			x1=x1+60;
			s=s+1;
	}
		else{
			x1=150;
			s=0;
			y1=y1+60;
		}
	}
	x1=x1;
	y1=y1;
	
}
void putvalue(int a,int b,int gen[9][9]){
	setbkcolor(BLUE);
	char aa;
	char cc[2];
	for(int i=0;i<9;i++){
		int x1=a;
		for(int j=0;j<9;j++){
			settextstyle(10,0,5);
			if(gen[i][j]==0){
				cc[0]=' ';
				cc[1]='\0';
			}
			else{
            aa='0'+ gen[i][j];
            cc[0]=aa;
            cc[1]='\0';
        }
    		outtextxy(x1+15,b+5,cc);
    		x1+=60;
		}
		b=b+60;
	}
}
void graphicsportion()
{	
	generator(gen);
	starttt=0;
    int x1,y1,x2,y2,a,b,c,d;
    int i,j;
    x1 = 150;
    y1 = 100;
    a = x1;
    b = y1;
    c = x1;
    d = y1;
    int s=1,ss=1,q=1,qq=1,e=1,ee=1,r=1,rr=1;
    for(i=1;i<10;i++)
    {
        x1 = a;
        for(j=1;j<10;j++)
        {
            x2 = x1 + 60;
            y2 = y1 + 60;
            if(gen[(y1/60)-1][(x1/60)-2]!=0){
            setfillstyle(SOLID_FILL,RED);
            rectangle(x1,y1,x2,y2);
        }
        else{
        	setfillstyle(SOLID_FILL,BLUE);
            rectangle(x1,y1,x2,y2);
        	
		}
            floodfill(x1+1,y1+1,WHITE);
            x1+=60;
        }
        y1+=60;

    }
    putvalue(a,b,gen);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(a,b,a+60,b+60);
    floodfill(a+1,b+1,WHITE);
    char ch;
    do
    {	
        ch = getch();
        if(ch=='d'||ch=='a'||ch=='w'||ch=='s')
        {
            if(ch=='d')
            {
                if(c!=630)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1+=60;
                    x2+=60;
                    int t=int(x1/60)-2;
					int tt=int(y1/60)-1;
					if(gen[tt][t]==0){
                    	makegreen(x1,y1,x2,y2);
                	}
					else{
						makered(x1,y1,x2,y2);
						s=0;
					}	
                    c+=60;
                    /*char ch1;
                    ch1 = getch();
                    char ch2[2];
                    ch2[0] = ch1;
                    ch2[1]='\0';
                    settextstyle(8,0,8);
                    //outtextxy(x1,y1,ch2);
                    */
                }
                else if(d!=580)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = a;
                    y1 = d + 60;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    int t=int(x1/60)-2;
					int tt=int(y1/60)-1;
					if(gen[tt][t]==0){
                    	makegreen(x1,y1,x2,y2);
                	}
					else{
						makered(x1,y1,x2,y2);
						ss=0;
					}	
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
                    int t=int(x1/60)-2;
					int tt=int(y1/60)-1;
					if(gen[tt][t]==0){
                    	makegreen(x1,y1,x2,y2);
                	}
					else{
						makered(x1,y1,x2,y2);
						r=0;
					}	
                    c-=60;
                }
                else if(d!=b)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = 630;
                    y1 = d - 60;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    int t=int(x1/60)-2;
					int tt=int(y1/60)-1;
					if(gen[tt][t]==0){
                    makegreen(x1,y1,x2,y2);
                	}
					else{
						makered(x1,y1,x2,y2);
						rr=0;
					}	
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
                    int t=int(x1/60)-2;
					int tt=int(y1/60)-1;
					if(gen[tt][t]==0){
                    makegreen(x1,y1,x2,y2);
                	}
					else{
						makered(x1,y1,x2,y2);
						q=0;
					}	
                    d+=60;
                }
                else if(c!=630)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = c+60;
                    y1 = b;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    int t=int(x1/60)-2;
					int tt=int(y1/60)-1;
					if(gen[tt][t]==0){
                    makegreen(x1,y1,x2,y2);
                	}
					else{
						makered(x1,y1,x2,y2);
						qq=0;
					}	
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
                    int t=int(x1/60)-2;
					int tt=int(y1/60)-1;
					if(gen[tt][t]==0){
                    makegreen(x1,y1,x2,y2);
                	}
					else{
						makered(x1,y1,x2,y2);
						e=0;
					}	
                    d-=60;
                }
                else if(c!=a)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = c-60;
                    y1 = 580;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    int t=int(x1/60)-2;
					int tt=int(y1/60)-1;
					if(gen[tt][t]==0){
                    	makegreen(x1,y1,x2,y2);
                	}
					else{
						makered(x1,y1,x2,y2);
						ee=0;
				 }	
                    c-=60;
                    d = 580;
                }
            }
        }
        else if(int(ch)>=49 && int(ch)<=57)
        {
        	if(gen[(int)(y1/60)-1][(int)(x1/60)-2]==0){
            	inputnumber(c,d,ch,gen);
        }
		}
    
    }while(ch!=' ');


    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
}
void startt(){
	if(starttt==1){
    settextstyle(10,0,7);
    outtextxy(275,20,"SudokuU");
    outtextxy(275,660,"Press F...");
    char chh;
    while(1){
	chh=getch();
	if(chh=='f'){
		outtextxy(275,660,"                                                             ");
        graphicsportion();  
	}
	}	
}
}
int main()
{
	generator(gen);
    int sudoku[9][9];
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
    		sudoku[i][j]=gen[i][j];
		}
	}
	int gd = DETECT,gm;
	initwindow(1000,750);
    startt();
	closegraph();
  	sudokuvalueinput();
}


