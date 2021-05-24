int gene[9][9]={1,0,5,2,0,0,0,6,0,
                   0,0,0,6,0,8,0,0,0,
                   8,6,0,9,0,0,0,4,1,
                   0,0,0,5,4,0,0,0,2,
                   0,9,0,0,0,0,0,7,0,
                   6,0,0,0,9,2,0,0,0,
                   4,8,0,0,0,7,0,2,9,
                   0,0,0,8,0,9,0,0,0,
                   0,7,0,0,0,1,5,0,3};
int sudokus[9][9]={1,0,5,2,0,0,0,6,0,
                   0,0,0,6,0,8,0,0,0,
                   8,6,0,9,0,0,0,4,1,
                   0,0,0,5,4,0,0,0,2,
                   0,9,0,0,0,0,0,7,0,
                   6,0,0,0,9,2,0,0,0,
                   4,8,0,0,0,7,0,2,9,
                   0,0,0,8,0,9,0,0,0,
                   0,7,0,0,0,1,5,0,3};
void makeblue(int c,int d,int*mx1,int*my1,int*mx2,int*my2)
{
    *mx1 = c;
    *my1 = d;
    *mx2 = *mx1 + 60;
    *my2 = *my1 + 60;
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(*mx1,*my1,*mx2,*my2);
    floodfill(*mx1+1,*my1+1,WHITE);
}

void makegreen(int mx1,int my1,int mx2,int my2)
{
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(mx1,my1,mx2,my2);
    floodfill(mx1+1,my1+1,WHITE);
}
void makered(int mx1,int my1,int mx2,int my2)
{
    setfillstyle(SOLID_FILL,RED);
    rectangle(mx1,my1,mx2,my2);
    floodfill(mx1+1,my1+1,WHITE);
}
void inputnumber(int mx1,int my1,char ch,int gene[9][9])
{
	int i,j,k;
    char ch1[2];
    ch1[0]=ch;
    ch1[1]='\0';
    j = (mx1/60)-2;
    i = (my1/60)-1;
    k = ch - '0';
    if(gene[i][j]==0){
    settextstyle(10,0,5);
    outtextxy(mx1+15,my1+5,ch1);
	}
    sudokus[i][j] = k;
}
void check(int gene[9][9],int mx1,int my1){
	int t=int(mx1/60)-2;
	int tt=int(my1/60)-1;
	int s=t;
	while(gene[tt][t]!=0){
		if(s<8){
			mx1=mx1+60;
			s=s+1;
	}
		else{
			mx1=150;
			s=0;
			my1=my1+60;
		}
	}
	mx1=mx1;
	my1=my1;
	
}
void putvalue(int a,int b,int gene[9][9]){
	setbkcolor(BLUE);
	char aa;
	char cc[2];
	for(int i=0;i<9;i++){
		int mx1=a;
		for(int j=0;j<9;j++){
			settextstyle(10,0,5);
			if(gene[i][j]==0){
				cc[0]=' ';
				cc[1]='\0';
			}
			else{
            aa='0'+ gene[i][j];
            cc[0]=aa;
            cc[1]='\0';
        }
    		outtextxy(mx1+15,b+5,cc);
    		mx1+=60;
		}
		b=b+60;
	}
}
void graphicsportion()
{	
    int mx1,my1,mx2,my2,a,b,c,d;
    int i,j;
    mx1 = 150;
    my1 = 100;
    a = mx1;
    b = my1;
    c = mx1;
    d = my1;
    int s=1,ss=1,q=1,qq=1,e=1,ee=1,r=1,rr=1;
    for(i=1;i<10;i++)
    {
        mx1 = a;
        for(j=1;j<10;j++)
        {
            mx2 = mx1 + 60;
            my2 = my1 + 60;
            if(gene[(my1/60)-1][(mx1/60)-2]!=0){
            setfillstyle(SOLID_FILL,RED);
            rectangle(mx1,my1,mx2,my2);
        }
        else{
        	setfillstyle(SOLID_FILL,BLUE);
            rectangle(mx1,my1,mx2,my2);
        	
		}
            floodfill(mx1+1,my1+1,WHITE);
            mx1+=60;
        }
        my1+=60;

    }
    putvalue(a,b,gene);
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
                    makeblue(c,d,&mx1,&my1,&mx2,&my2);
                    mx1+=60;
                    mx2+=60;
                    int t=int(mx1/60)-2;
					int tt=int(my1/60)-1;
					if(gene[tt][t]==0){
                    	makegreen(mx1,my1,mx2,my2);
                	}
					else{
						makered(mx1,my1,mx2,my2);
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
                    makeblue(c,d,&mx1,&my1,&mx2,&my2);
                    mx1 = a;
                    my1 = d + 60;
                    mx2 = x1 + 60;
                    my2 = y1 + 60;
                    int t=int(mx1/60)-2;
					int tt=int(my1/60)-1;
					if(gene[tt][t]==0){
                    	makegreen(mx1,my1,mx2,my2);
                	}
					else{
						makered(mx1,my1,mx2,my2);
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
                    makeblue(c,d,&mx1,&my1,&mx2,&my2);
                    mx1-=60;
                    mx2-=60;
                    int t=int(mx1/60)-2;
					int tt=int(my1/60)-1;
					if(gene[tt][t]==0){
                    	makegreen(mx1,my1,mx2,my2);
                	}
					else{
						makered(mx1,my1,mx2,my2);
						r=0;
					}	
                    c-=60;
                }
                else if(d!=b)
                {
                    makeblue(c,d,&mx1,&my1,&mx2,&my2);
                    mx1 = 630;
                    my1 = d - 60;
                    mx2 = mx1 + 60;
                    my2 = my1 + 60;
                    int t=int(mx1/60)-2;
					int tt=int(my1/60)-1;
					if(gene[tt][t]==0){
                    makegreen(mx1,my1,mx2,my2);
                	}
					else{
						makered(mx1,my1,mx2,my2);
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
                    makeblue(c,d,&mx1,&my1,&mx2,&my2);
                    my1+=60;
                    my2+=60;
                    int t=int(mx1/60)-2;
					int tt=int(my1/60)-1;
					if(gene[tt][t]==0){
                    makegreen(mx1,my1,mx2,my2);
                	}
					else{
						makered(mx1,my1,mx2,my2);
						q=0;
					}	
                    d+=60;
                }
                else if(c!=630)
                {
                    makeblue(c,d,&mx1,&my1,&mx2,&my2);
                    mx1 = c+60;
                    my1 = b;
                    mx2 = mx1 + 60;
                    my2 = my1 + 60;
                    int t=int(mx1/60)-2;
					int tt=int(my1/60)-1;
					if(gene[tt][t]==0){
                    makegreen(mx1,my1,mx2,my2);
                	}
					else{
						makered(mx1,my1,mx2,my2);
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
                    makeblue(c,d,&mx1,&my1,&mx2,&my2);
                    my1-=60;
                    my2-=60;
                    int t=int(mx1/60)-2;
					int tt=int(my1/60)-1;
					if(gene[tt][t]==0){
                    makegreen(mx1,my1,mx2,my2);
                	}
					else{
						makered(mx1,my1,mx2,my2);
						e=0;
					}	
                    d-=60;
                }
                else if(c!=a)
                {
                    makeblue(c,d,&mx1,&my1,&mx2,&my2);
                    mx1 = c-60;
                    my1 = 580;
                    mx2 = mx1 + 60;
                    my2 = my1 + 60;
                    int t=int(mx1/60)-2;
					int tt=int(my1/60)-1;
					if(gene[tt][t]==0){
                    	makegreen(mx1,my1,mx2,my2);
                	}
					else{
						makered(mx1,my1,mx2,my2);
						ee=0;
				 }	
                    c-=60;
                    d = 580;
                }
            }
        }
        else if(int(ch)>=49 && int(ch)<=57)
        {
        	if(gene[(int)(my1/60)-1][(int)(mx1/60)-2]==0){
            	inputnumber(c,d,ch,gene);
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

